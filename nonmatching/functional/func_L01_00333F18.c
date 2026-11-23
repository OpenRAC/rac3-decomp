/* functional: high. Draft from nonmatching (86 words differ, byte layout only); every branch, offset, callee (func_00382468 = frontbin RNG, same as func_L01_00443948 here) re-read against the PAL asm. Needs Vt00335B98, Fn_335C70, u128_t from L01_003326A8.c context. */
/* localdecomp:start func_L01_00333F18 */
extern u8 *D_L01_001E001C;
extern u128_t D_L01_001D66B0;
void func_L01_00333F18(u8 *obj)
{
    extern Vt00335B98 *func_L01_0043B568(s32, s32, s32);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern void func_L01_00334188(u8 *, u8 *);
    extern void func_L01_00456230(u8 *, s32);
    extern s32 func_00382468(s32);
    extern int func_L01_00335EC0(u8 *, int);
    u8 *d=*(u8 **)(obj+0x68);
    u8 *cfg=*(u8 **)(*(u8 **)(obj+0xB8)+0x68);
    Vt00335B98 *vt=func_L01_0043B568(*(s32 *)(d+0x40),4,0x9C);
    u8 *work=vt->fn(D_L01_001E001C+(*(s32 *)(d+0x50)<<8));
    if(cfg[0x8F]!=0 && obj[0x20]!=16 && (s8)d[0x5C]+5!=16) {
        func_L01_004450F0(obj,16,-1);
        return;
    }
    func_L01_004450F0(obj,(s8)d[0x5C]+5,-1);
    d[0x5D]=d[0x5E]=0;
    *(s8 *)(d+0x5C)=-1;
    func_L01_00334188(cfg,work);
    if(cfg[0x95]!=0) func_L01_00456230(obj,1);
    if(*(s32 *)(cfg+0x6C)!=-1 && cfg[0x99]!=0)
        *(s32 *)(work+0x1CC)=*(s32 *)(cfg+0x6C);
    else
        *(s32 *)(work+0x1CC)=-1;
    *(s32 *)(d+0x7C)=*(s32 *)(cfg+0x7C);
    if(cfg[0x98]!=0) {
        *(s32 *)(work+0x244)=0;
        *(s32 *)(work+0x240)=0;
        *(u128_t *)(work+0x230)=D_L01_001D66B0;
    }
    if(*(s32 *)(d+0x4C)!=-1) {
        u8 *other=*(u8 **)((*(s32 *)(d+0x4C)<<8)+(s32)D_L01_001E001C+0x68);
        if(other[0x9A]!=0 && *(s32 *)(other+0x78)!=-1 && cfg[0x1A]==0) {
            if(other[0x9B]>=100 || func_00382468(100)<other[0x9B])
                func_L01_00335EC0(obj,*(s32 *)(other+0x78));
        } else if(cfg[0x9A]==0 && *(s32 *)(cfg+0x78)!=-1 && cfg[0x1A]==0) {
            if(cfg[0x9B]>=100 || func_00382468(100)<cfg[0x9B])
                func_L01_00335EC0(obj,*(s32 *)(cfg+0x78));
        }
        if(other[0x90]!=0)
            ((Fn_335C70 *)vt)[0x88/4](D_L01_001E001C+(*(s32 *)(d+0x50)<<8));
        else if(other[0x91]!=0)
            ((Fn_335C70 *)vt)[0x8C/4](D_L01_001E001C+(*(s32 *)(d+0x50)<<8));
    }
}
/* localdecomp:end func_L01_00333F18 */
