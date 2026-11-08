/* Ported from rac4-decomp's func_0053CB70 (a twin of this function's code), names renamed from retail's
   relocations; 3 instruction(s) still differ under this file's flags. */
typedef struct {
    u32 f0;
    u32 f4;
    char p8[0x44];
    u32 f4C;
} Type1;
typedef struct {
    u8 pad[0x218];
    u32 tick;
} Profile00172160;
extern Profile00172160 D_001A5CD0;

void func_L39_00662B68(Type1 *a, s32 b, s32 c)
{
    u32 p = D_001A5CD0.tick;
    a->f4 = p;
    if (c > 0)
        a->f0 = (a->f0 & 0x1fff) |
                ((D_001A5CD0.tick + b + c - p) << 13);
    else
        a->f0 &= 0x1fff;
    a->f4C = D_001A5CD0.tick + b;
}