/* functional: high. EXACT under the file's flags at level 01 (check.py MATCH). */
__asm__(".extern D_L01_001DCA34, 4");
__asm__(".extern D_L01_001DCA38, 4");
__asm__(".extern D_L01_001DCA3C, 4");
__asm__(".extern D_L01_001DCA40, 4");
extern f32 D_L01_001DCA34, D_L01_001DCA38, D_L01_001DCA3C, D_L01_001DCA40;
void func_L01_00328280(s32 unused, u8 *save) {
    extern void func_L01_00516468(s32);
    extern void func_003B5060(s32);
    extern void func_003E5090(s32);
    extern s32 func_00392A18(void);
    extern s32 func_L01_00517448(s32, s32, s32);
    extern void func_L01_00516470(s32, f32, f32);
    extern void func_L01_005170B8(s32, s32);
    extern void func_L01_00517538(s32, f32, f32);
    extern void func_003E8630(s32, s32);
    extern void func_003E8348(s32, s32);
    if (*(s32 *)(*(u8 **)(*(u8 **)(save+0x30)+0x68)+0x30)==0) {
        func_L01_00516468(1);
        func_003B5060(0x30000);
        func_003E5090(0x30001);
        func_003E5090(0x30002);
        func_003E5090(0x30003);
        func_L01_00517448(0x30001,func_00392A18(),0x2F);
        func_L01_00517448(0x30002,func_00392A18(),0x30);
        func_L01_00517448(0x30003,func_00392A18(),0x31);
        func_L01_00516470(0x30001,D_L01_001DCA34,D_L01_001DCA38);
        func_L01_00516470(0x30002,D_L01_001DCA34,D_L01_001DCA38);
        func_L01_00516470(0x30003,D_L01_001DCA34,D_L01_001DCA38);
        func_L01_005170B8(0x30001,0x332299DE);
        func_L01_005170B8(0x30002,0x331465B7);
        func_L01_005170B8(0x30003,0x331465B7);
        func_L01_00517538(0x30001,D_L01_001DCA3C,D_L01_001DCA40);
        func_L01_00517538(0x30002,D_L01_001DCA3C,D_L01_001DCA40);
        func_L01_00517538(0x30003,D_L01_001DCA3C,D_L01_001DCA40);
        func_003E8630(0x30000,0x30002);
        func_003E8630(0x30000,0x30001);
        func_003E8630(0x30000,0x30003);
        func_003E8348(0x15,0x30000);
        func_L01_00516468(0);
    }
}
