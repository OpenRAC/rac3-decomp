/* functional: high. Codex near-miss draft verified against the PAL assembly and jtbl_0031C690 (cases 3..32; 11, 18, 28 draw nothing); the two string lookups feeding func_0011B2E8 are now taken in retail order (0x199 then 0x19A, 0x1A2 then 0x11E8) through temporaries instead of unspecified argument order. Colour 0x8066CCFF and 0x80000000 passed zero-extended as retail. 278 words differ (regalloc/scheduling). */
extern u8 D_001D88A0[];
extern u8 D_001D88A8[];
extern u8 D_00240820[];
extern s8 D_001D9FA0[];
extern u8 D_001D5BDC __attribute__((section(".data")));
extern u8 D_001D5BDD __attribute__((section(".data")));
extern s32 D_001D4BC8[];
extern s32 D_001D4BCC[];
extern s32 D_001D4CE8 __attribute__((section(".data")));
void func_003B3D98(void) {
    extern s32 func_003823D0();
    extern void func_0011B2E8();
    extern void func_0038EBC8_003B3BF8(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
    s32 title=(s32)D_001D88A0;
    s32 left=0;
    s32 right=0;
    s32 show=1;
    s32 fmt, arg;
    switch(D_001D4CE8) {
    case 8:
        left=func_003823D0(0x8E3);
        right=func_003823D0(0x8DF);
        title=func_003823D0(0x1A3);
        break;
    case 14:
        if((u8)D_001D9FA0[0]) goto dual;
    case 15:
        left=func_003823D0(0x8E3);
        right=func_003823D0(0x8DF);
        title=func_003823D0(0x1A0);
        break;
    case 12:case 13:case 31:case 32:
        title=func_003823D0(0x1AF);break;
    case 9:case 10:
        title=func_003823D0(0x1AD);break;
    case 16:case 17:
        title=func_003823D0(0x1AE);break;
    case 25:case 29:
        title=func_003823D0(0x1AB);break;
    case 23:case 30:
        title=func_003823D0(0x1AC);break;
    case 19:
        title=func_003823D0(0x1B0);
        left=func_003823D0(0x8DE);break;
    case 20:
        title=func_003823D0(0x1B2);
        left=func_003823D0(0x8DE);break;
    case 3:
        title=func_003823D0(0x194);break;
    case 21:
        if((u8)D_001D9FA0[0]) goto dual;
        if(D_001D5BDC) {
            title=(s32)D_00240820;
            fmt=func_003823D0(0x199);
            arg=func_003823D0(0x19A);
            func_0011B2E8((u8 *)title,D_001D88A8,fmt,1,1,arg);
            left=func_003823D0(0x8E2);
            right=func_003823D0(0x8DF);
        } else {
            title=(s32)D_00240820;
            fmt=func_003823D0(0x199);
            arg=func_003823D0(0x19A);
            func_0011B2E8((u8 *)title,D_001D88A8,fmt,1,1,arg);
            left=func_003823D0(0x8E2);
        }
        break;
    case 24:
        title=func_003823D0(0x1B3);
        left=func_003823D0(0x8DE);break;
    case 22:
        title=func_003823D0(0x1B1);
        left=func_003823D0(0x8DE);break;
    case 27:
        left=func_003823D0(0x8E2);
        right=func_003823D0(0x8DF);
        title=(s32)D_00240820;
        fmt=func_003823D0(0x1A2);
            arg=func_003823D0(0x11E8);
            func_0011B2E8((u8 *)title,D_001D88A8,fmt,1,1,arg);
        break;
    case 26:
        left=func_003823D0(0x8E2);
        right=func_003823D0(0x8DF);
        title=func_003823D0(0x1A5);
        break;
    case 4:case 5:case 6:
        if(D_001D5BDC && !(u8)D_001D9FA0[0]) {
            left=func_003823D0(0x8E2);
            right=func_003823D0(0x8DF);
            title=func_003823D0(0x19C);
        } else if(D_001D5BDD) {
            left=func_003823D0(0x8E2);
            title=func_003823D0(0x19C);
        } else {
            title=func_003823D0((u8)D_001D9FA0[0] ? 0x196 : 0x19E);
            left=func_003823D0(0x197);
        }
        break;
    case 7:
    dual:
        title=func_003823D0(0x196);
        left=func_003823D0(0x197);break;
    default:show=0;break;
    }
    if(show) {
        if(title) func_0038EBC8_003B3BF8(D_001D4BC8[0],D_001D4BCC[0],1.0f,0x8066CCFFUL,title,-1,1.0f,1,0,0x80000000UL,0.0f,0.0f);
        if(left) func_0038EBC8_003B3BF8(D_001D4BC8[0]-100,D_001D4BCC[0]+70,1.0f,0x8066CCFFUL,left,-1,1.0f,1,0,0x80000000UL,0.0f,0.0f);
        if(right) func_0038EBC8_003B3BF8(D_001D4BC8[0]+100,D_001D4BCC[0]+70,1.0f,0x8066CCFFUL,right,-1,1.0f,1,0,0x80000000UL,0.0f,0.0f);
    }
}
