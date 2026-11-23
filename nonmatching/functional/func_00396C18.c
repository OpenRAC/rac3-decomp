/* functional: high. US draft corrected for PAL: fade step is 0x12 (draft had 0x10); gp globals verified (gp=0x1DC8B0). Only reg alloc/scheduling differs. */
typedef struct { u8 p0[0x18]; void (*f18)(void *); u8 p1c[0x74]; } S_391FD8;
extern S_391FD8 D_00331AE0_00396C18[];
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern s32 D_001D9E94;
extern s32 D_001D9DF8;
extern s32 D_001D9DFC;
extern s32 D_001D9E00;
extern s32 D_001D5B94;
void func_00396C18(void) {
    S_391FD8 *p;
    s32 i;
    if (D_001D9EC0 || D_001D9BDC) {
        D_001D9EC0 = 0;
        return;
    }
    D_001D9E94 = 0xFFFFF0;
    p = D_00331AE0_00396C18;
    for (i = 12; i >= 0; i--) {
        if (p->f18) p->f18(p);
        p++;
    }
    if (D_001D9DF8 || D_001D9DFC) {
        if (D_001D5B94 == 0) {
            if (D_001D9DF8) {
                D_001D9DFC += 0x12;
                if (D_001D9DFC > 0x80) D_001D9DFC = 0x80;
            } else {
                D_001D9DFC -= 0x12;
                if (D_001D9DFC < 0) D_001D9DFC = 0;
            }
            if (D_001D9DF8) D_001D9DF8--;
            if (D_001D9DF8 == 1000) D_001D9DF8 = 0;
            return;
        }
    }
    D_001D9E00 = 100;
}
