/* functional: high. Ported from the byte-exact NTSC-U draft and re-read against the PAL assembly; PAL differences: 17-frame sound cooldown (0xBC) instead of 20; shake counter 17, 0.04 spark velocity scale and 0.098 descent step (the 60 Hz values), PAL callee and global names. Moving platform/crate controller: state 0 initialises ride list, probes the floor with a collision test and picks the object under it; state 1 keeps it aligned, explodes when its health at +0x30 runs out and lowers to the floor otherwise. */
/* localdecomp:start func_L03_0034B6C0 */
typedef int Q_0034B6C0 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0034B6C0;
extern s32 func_L01_0044C108(void *);
extern f32 func_003C3D30(void *,s32,s32,f32);
extern void func_L01_00439880(void *,u16 *,s32 *);
extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
extern void func_L01_004450F0(void *,s32,s32);
extern s32 func_L01_00452F78(void *,s32,s32,s32);
extern void func_003A52A0(s32,s32,void *);
extern void func_0038CF68(void *,void *,f32);
extern void func_L01_00451FE0(void *,s32,void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,f32,f32,f32,f32);
extern void func_L03_0034BBA0(void *);
extern void func_003C2880(void *);
extern s32 func_L03_0034BC80(void *,void *);
extern f32 func_003824E0(f32,f32);
extern u8 D_L03_001FC3D0[];
extern u8 *D_L03_001E9218[];
extern u8 D_L03_001E24C0[];
void func_L03_0034B6C0(u8 *m) {
    V_0034B6C0 bottom,top;
    u16 result;
    s32 result2;
    u8 *v;
    s32 i;
    u16 old;
    f32 height;
    if(!func_L01_0044C108(m+0x10)) return;
    v=*(u8 **)(m+0x68);
    switch(m[0x20]) {
    case 0:
        *(u16 *)(m+0x34)|=0x100;
        *(u16 *)(v+0x152)=0;
        for(i=0;i<2;i++) {
            if(((s32 *)(v+0x154))[i]!=-1) (*(u16 *)(v+0x152))++;
        }
        for(i=0;i<2;i++) {
            if(D_L03_001FC3D0[((s32 *)(v+0x154))[i]]==255) *(u16 *)(v+0x152)=0;
        }
        *(f32 *)(m+0x18)=func_003C3D30(m+0x10,0,0,0.5f);
        func_L01_00439880(m,&result,&result2);
        *(Q_0034B6C0 *)&top=*(Q_0034B6C0 *)(m+0x10);
        *(Q_0034B6C0 *)&bottom=*(Q_0034B6C0 *)(m+0x10);
        top.z+=0.5f;
        bottom.z-=1.0f;
        *(u16 *)(m+0x7C)=result;
        if(func_003D3CB0(&top,&bottom,0,m,0)) {
            if(D_L03_001E9218[0]) {
                u8 *other;
                *(u16 *)(v+0x152)=0;
                other=D_L03_001E9218[0];
                *(u8 **)(v+0x15C)=other;
                *(Q_0034B6C0 *)(m+0xF0)=*(Q_0034B6C0 *)(other+0x10);
            }
        }
        *(u16 *)(v+0x152)|=0x80;
        if(*(f32 *)(v+0x30)<=0.0f) *(f32 *)(v+0x30)=30.0f;
        if(*(s16 *)(v+0x34)<=0) *(f32 *)(v+0x30)=30.0f;
        func_L01_004450F0(m,1,-1);
    case 1:
        old=*(u16 *)(m+0x7C);
        if(func_L01_00452F78(m,0,0,0)) *(u16 *)(v+0x36)=*(u16 *)(v+0x150);
        if(old!=*(u16 *)(m+0x7C) && !m[0xBC]) {
            func_003A52A0(0,0,m);
            m[0xBC]=17;
        }
        if(m[0xBC]) m[0xBC]--;
        if(*(f32 *)(v+0x30)<=0.0f) {
            *(Q_0034B6C0 *)&bottom=*(Q_0034B6C0 *)(m+0xE0);
            func_0038CF68(&bottom,&bottom,0.04f);
            func_L01_00451FE0(m,65535,&bottom,255,180,0,0,35,0,3,3.0f,6.0f,3.0f,6.0f,-1.0f,-1.0f,1.0f,1.0f);
            func_003A52A0(0,0,m);
            func_L03_0034BBA0(m);
            func_003C2880(m);
            return;
        }
        if(*(u8 **)(v+0x15C)) {
            u8 *other=*(u8 **)(v+0x15C);
            if(other[0x20]==254 || other[0x20]==253) {
                *(u8 **)(v+0x15C)=0;
                *(u16 *)(v+0x152)&=0xFF7F;
            }
            if(*(u8 **)(v+0x15C) && !func_L03_0034BC80(*(u8 **)(v+0x15C)+0x10,m+0xF0)) goto lower;
        }
        if(*(u16 *)(v+0x152)&0x80) return;
lower:
        *(u16 *)(v+0x152)&=0xFF7F;
        height=func_003C3D30(m+0x10,0,0,0.5f);
        if(height<*(f32 *)(m+0x18)) {
            *(f32 *)(m+0x18)-=0.098f;
            if(*(f32 *)(m+0x18)<height) {
                *(f32 *)(D_L03_001E24C0+0x20)=func_003824E0(0.0f,0.25f);
                *(s32 *)(D_L03_001E24C0+0x28)=17;
                *(s32 *)(D_L03_001E24C0+0x2C)=0;
                *(f32 *)(m+0x18)=height;
                *(u16 *)(v+0x152)|=0x80;
            }
        }
        break;
    }
}
/* localdecomp:end func_L03_0034B6C0 */
