/* Ported from rac2-decomp's func_L06_003660F0 (a twin of this function's code), names renamed from retail's
   relocations; 8 instruction(s) still differ under this file's flags. */
extern unsigned char D_001A7A47 __attribute__((section(".data")));

extern void func_L01_0043A430(unsigned char *, unsigned int, unsigned char *);
extern void func_003C2C98(char *, char *);

void func_L07_004522E8(unsigned char *object, unsigned int index,
                       unsigned char *node, float value)
{
    if (D_001A7A47 != 0) {
        if (node[1] == 0)
            func_L01_0043A430(object, index, node);
        *(float *)(node + 0x20) = value;
        *(float *)(node + 0x24) = value;
        *(float *)(node + 0x28) = value;
    } else if (node[1] != 0) {
        func_003C2C98((char *)object, (char *)node);
    }
}