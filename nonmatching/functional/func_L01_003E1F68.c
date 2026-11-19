/* functional: high. 37 diff vs retail; draft retyped (u8 *) so it compiles in context; stage fallthrough 1->2->3 and loops verified vs asm; gp consts D_001DF590..5A0 */
/* localdecomp:start func_L01_003E1F68 */
extern f32 D_L01_001DF590;
__asm__(".extern D_L01_001DF590, 4");
extern f32 D_L01_001DF594;
__asm__(".extern D_L01_001DF594, 4");
extern f32 D_L01_001DF598;
__asm__(".extern D_L01_001DF598, 4");
extern f32 D_L01_001DF59C;
__asm__(".extern D_L01_001DF59C, 4");
extern f32 D_L01_001DF5A0;
__asm__(".extern D_L01_001DF5A0, 4");
void func_L01_003E1F68(u8 *m)
{
    extern void func_L01_003E2418(u8 *,u8 *);
    extern void func_L01_003E2BD8(u8 *,u8 *);
    extern void func_L01_004450F0(u8 *,s32,s32);
    extern void func_L01_003E2DB8(u8 *);
    extern s32 func_L01_004048D0(void (*)(u8 *),u8 *);
    extern void func_003C2880(u8 *);
    u8 *vars=*(u8 **)(m+0x68);
    s32 i,alpha;
    u8 **children;
    switch (m[0x20]) {
    case 1:
        *(f32 *)(vars+8)+=D_L01_001DF590;
        if (*(f32 *)(vars+8)>=1.0f) {
            *(f32 *)(vars+8)=0.0f;
            func_L01_004450F0(m,2,-1);
        } else {
            func_L01_003E2418(m,vars);
            func_L01_004048D0(func_L01_003E2DB8,m);
            break;
        }
    case 2:
        *(f32 *)(vars+8)+=D_L01_001DF594;
        if (*(f32 *)(vars+8)>=1.0f) {
            (*(u8 **)(m+0xB8))[0x23]=128;
            for (i=0;i<*(s32 *)(vars+0xC);i++) {
                (*(u8 **)(vars+0x20+i*4))[0x23]=128;
            }
            *(f32 *)(vars+8)=0.0f;
            func_L01_004450F0(m,3,-1);
        } else {
            func_L01_003E2BD8(m,vars);
            if (*(f32 *)(vars+8)<=D_L01_001DF59C) alpha=0;
            else if (*(f32 *)(vars+8)>=D_L01_001DF5A0) alpha=128;
            else alpha=(s32)((*(f32 *)(vars+8)-D_L01_001DF59C)/(D_L01_001DF5A0-D_L01_001DF59C)*128.0f);
            if (alpha>=2) {
                *(u16 *)(*(u8 **)(m+0xB8)+0x34)&=~1;
                (*(u8 **)(m+0xB8))[0x31]=1;
                (*(u8 **)(m+0xB8))[0x23]=alpha;
                for (i=0,children=(u8 **)(vars+0x20);i<*(s32 *)(vars+0xC);i++,children++) {
                    *(u16 *)(*children+0x34)&=~1;
                    (*children)[0x31]=1;
                    (*children)[0x23]=alpha;
                }
            }
            func_L01_004048D0(func_L01_003E2DB8,m);
            break;
        }
    case 3:
        *(f32 *)(vars+8)+=D_L01_001DF598;
        if (*(f32 *)(vars+8)>=1.0f) func_003C2880(m);
        else func_L01_003E2BD8(m,vars);
        break;
    }
}
/* localdecomp:end func_L01_003E1F68 */
