/* functional: high. functional: high. PAL draft from nonmatching/levels, 4-word scheduling difference only */
typedef int W76Quad __attribute__((mode(TI)));
extern u8 *func_003C24B0(int,int);
extern float func_0038CED8(void *);
extern float func_0038D160(float,float);
extern void func_0038D308(void *,void *);
extern float D_L01_001DF1D8;
extern int D_L01_001DF1F0;
__asm__(".extern D_L01_001DF1D8,4");
__asm__(".extern D_L01_001DF1F0,4");
typedef struct { W76Quad q0; int x10; float x14; int x18; int x1c; float x20; float x24; int x28; int x2c; } D_3CE780;
u8 *func_L01_003CE780(void *parent,void *position,u8 *direction,int kind,int other,float scale) {
    u8 *m;
    D_3CE780 *d;
    float speed; int color;
    m=func_003C24B0(0x1B62,0x80);
    if(m) {
        *(void **)(m+0xB8)=parent;
        *(u16 *)(m+0x34)|=1;
        m[0x31]=0;
        d=*(D_3CE780 **)(m+0x68);
        m[0x30]=255;
        func_L01_004450F0((M3C7568 *)m,1,-1);
        *(W76Quad *)(m+0x10)=*(W76Quad *)position;
        *(float *)(m+0xF4)=-func_0038D160(func_0038CED8(direction),*(float *)(direction+8));
        *(float *)(m+0xF8)=func_0038D160(*(float *)direction,*(float *)(direction+4));
        func_0038D308(m+0xC0,m+0xF0);
        *(W76Quad *)d=*(W76Quad *)direction;
        speed=D_L01_001DF1D8;
        d->x14=scale;
        color=D_L01_001DF1F0;
        d->x20=speed;
        d->x1c=color;
        d->x24=1.0f;
        d->x18=500;
        d->x28=kind;
        d->x2c=other;
    }
    return m;
}

