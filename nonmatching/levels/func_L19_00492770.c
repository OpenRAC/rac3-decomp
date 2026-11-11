/* func_L19_00492770: 79 diff (register numbering); jump table and all control flow match */
typedef struct { u32 f0; u32 f4; u32 f8; u32 *fC; u32 f10; u8 f14; u8 p15[3]; } S_492770;
extern S_492770 D_L19_002EF138[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
__asm__(".extern D_001D9418, 4");
extern s32 D_001D9418;

void func_L19_00492770(void) {
    s32 i = 0;
    s32 n;
    S_492770 *e;
    u32 **pp;
    s32 j;
    s32 g;
    while (D_L19_002EF138[i].f0 != 0) {
        switch (D_L19_002EF138[i].f10) {
        case 1:
            e = &D_L19_002EF138[i];
            pp = (u32 **)((u8 *)D_L19_002EF138 + 0xC + i * 0x18);
            n = i + 1;
            e->f14 = 1;
            if ((*pp)[0] != 0) {
                j = 0;
                g = D_001D9418;
                do {
                    e->f14 = (e->f14 != 0 && (*(u32 *)((u8 *)D_00142BA0 + (((*pp)[j] >> 2) << 2)) & (1 << ((*pp)[j] & 0x1F))) != 0) || g != 0;
                    j++;
                } while ((*pp)[j] != 0);
            }
            break;
        case 0:
        case 2:
            e = &D_L19_002EF138[i];
            n = i + 1;
            e->f14 = (*(u32 *)((u8 *)D_00142BA0 + (((u32)e->fC >> 2) << 2)) & (1 << ((u32)e->fC & 0x1F))) != 0 || D_001D9418 != 0;
            break;
        case 3:
            e = &D_L19_002EF138[i];
            n = i + 1;
            e->f14 = D_00142693[0] != 0 || D_001D9418 != 0;
            break;
        case 4:
        default:
            n = i + 1;
            D_L19_002EF138[i].f14 = 1;
            break;
        }
        i = n;
    }
}
