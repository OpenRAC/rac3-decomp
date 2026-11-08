/* Ported from rac4-decomp's func_004E55C0 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct {
    char p0[32];
    u8 f20;
    char p21[19];
    u16 f34;
    char p36[134];
    s16 fBC;
    char pBE[66];
} Type1;
extern Type1 *D_L01_001E0020;

void func_L01_004B9798(s32 enabled)
{
    Type1 *p = D_L01_001E0020;
    while (p->f20 != 255) {
        if (!(p->f20 & 128) && (p->fBC == 0x183A || p->fBC == 0x183C)) {
            if (enabled)
                p->f34 |= 128;
            else
                p->f34 &= 0xFF7F;
        }
        p++;
    }
}