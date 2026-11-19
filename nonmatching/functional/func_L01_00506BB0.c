/* functional: high. Near-miss draft; the 90 diff lines are scheduling and base-register reuse, same instruction multiset except the equivalent sltu/sltiu+movz form of the 7-or-12 pick. */
/* localdecomp:start func_L01_00506BB0 */
extern u8 D_001A4BE0[];
extern Pad_5075D8 *D_001D52FC;
extern s32 D_L01_001DBE34;
void func_L01_00506BB0(void) {
    extern void func_L01_004EE850(s32,f32);
    extern s32 func_003A3BB8(s32,s32);
    /* Retail consumes this return at 0x114, 0x1A4 and 0x200.
       The owner currently declares this callee void; integration needs correction. */
    extern s32 func_L01_005003D0(s32,s32);
    extern void func_L01_0050FB40(s32,s32,f32);
    extern void func_L01_0050FE88(s32,s32);
    extern s32 func_L01_004DFDB0(s32);
    extern void func_003C4BB0(void *,f32);
    u8 *h=D_001A4BE0;
    *(s32 *)(h+0x280c)=0;
    if (h[0x1474] && *(f32 *)(h+0x174)>0.010000000707805157f) {
        func_L01_005003D0(46,1);
        return;
    }
    func_L01_004EE850(0,1.0f);
    if (D_001D52FC->held & func_003A3BB8(8,0)) {
        func_L01_005003D0(4,0);
        func_L01_0050FB40(13,2,-2.0f);
        func_L01_0050FE88(3,18);
    } else if (*(f32 *)(h+0x2838)>0.3f && *(s16 *)(h+0x1e0)==0) {
        if (h[0x1474] || h[0x25ea]) {
            func_L01_005003D0(2,1);
        } else if (func_L01_005003D0(2,0)) {
            s32 frames=h[0x46c]<5?7:12;
            *(s32 *)(h+0x25c8)=1;
            func_L01_0050FB40(4,D_L01_001DBE34,(f32)frames);
            h[0x3ee]=1;
        }
    } else if ((*(f32 *)(h+0x178)>0.06000000238418579f && h[0x46c]>=3) || *(s32 *)(h+0x25c4)==16) {
        if (func_L01_005003D0(3,0)) {
            func_L01_0050FB40(5,0,-1.0f);
            func_003C4BB0(D_001A4BE0+0x160,0.10000000894069672f);
        }
    } else if (h[0x46c]>=11 || (*(u32 *)(h+0xc08)&2)) {
        if (func_L01_005003D0(0,0)) {
            if (func_L01_004DFDB0(0)==74) {
                func_L01_0050FB40(func_L01_004DFDB0(0),0,12.0f);
            } else if (*(u32 *)(h+0xc08)&2) {
                func_L01_0050FB40(func_L01_004DFDB0(0),0,-2.0f);
            }
        }
    }
}
/* localdecomp:end func_L01_00506BB0 */
