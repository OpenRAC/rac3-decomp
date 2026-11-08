/* Ported from rac2-decomp's func_002B6828 (a twin of this function's code), names renamed from retail's
   relocations; 5 instruction(s) still differ under this file's flags. */
typedef struct { char pad[0x17a0]; unsigned int status[1]; } BankStatuses;
typedef struct { int offset, size; } SoundEntry;
typedef struct {
    char pad[0x529c];
    int base;
    char gap[0x40];
    SoundEntry entries[1];
} BankLoadTable;
typedef struct { char pad[0x17a4]; unsigned int status[1]; } BankCallbackStatuses;
extern int D_001F0A00[];
extern void func_00193888(void *, int, void (*)(int, long), unsigned long);
extern char D_001FE020[];
extern void func_L01_0045E690(int, long);

void func_L39_005C1368(int index)
{
    int *d = D_001F0A00;
    int offset = ((BankLoadTable *)d)->entries[index].offset;
    BankStatuses *b;
    if (offset) {
        unsigned int out;
        b = (BankStatuses *)D_001FE020;
        b->status[index + 1] = -1;
        out = (unsigned int)((unsigned long)(unsigned int)((BankCallbackStatuses *)b)->status
                             + index * 4);
        func_00193888((void *)(offset + d[0x14a7]), 0, func_L01_0045E690,
                      (unsigned long)(unsigned int)out);
    } else {
        ((BankStatuses *)D_001FE020)->status[index + 1] = 0;
    }
}