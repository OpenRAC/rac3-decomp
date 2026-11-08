#include "common.h"

/* localdecomp:start func_L39_005C1310 */
extern char D_001FE020[];
extern int D_001F0A00[];
extern void func_L01_0045E690(int, long);
extern void func_00193888(void *, int, void (*)(int, long), unsigned long);

/* from rac2-decomp's func_002B6788 */
void func_L39_005C1310(void) {
    char *b = D_001FE020;
    int *d = D_001F0A00;
    *(unsigned int *)(b + 0x90) = 0xFFFFFFFFu;
    func_00193888((void *)(d[0x1E6E] + d[0x1E69]), 0, func_L01_0045E690,
                  (unsigned long)(unsigned int)(b + 0x90));
}
/* localdecomp:end func_L39_005C1310 */

/* localdecomp:start func_L39_005C1368 */
typedef struct { char pad[0x90]; unsigned int status[1]; } BankStatuses;
typedef struct { int offset, size; } SoundEntry;
typedef struct {
    char pad[0x79a4];
    int base;
    char gap[0x40];
    SoundEntry entries[1];
} BankLoadTable;
typedef struct { char pad[0x94]; unsigned int status[1]; } BankCallbackStatuses;
extern int D_001F0A00[];
extern void func_00193888(void *, int, void (*)(int, long), unsigned long);
extern char D_001FE020[];
extern void func_L01_0045E690(int, long);

/* from rac2-decomp's func_002B6828 */
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
        func_00193888((void *)(offset + d[0x1e69]), 0, func_L01_0045E690,
                      (unsigned long)(unsigned int)out);
    } else {
        ((BankStatuses *)D_001FE020)->status[index + 1] = 0;
    }
}
/* localdecomp:end func_L39_005C1368 */
