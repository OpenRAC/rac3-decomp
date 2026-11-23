/* functional: high. VU0 vsub/vadd written as plain float ops (w ignored in both); the .extern asm hack of the draft dropped, D_L01_001DD6D4 is a normal gp-addressed f32. */
typedef struct { u8 pad0; u8 active; u8 pad2[238]; } Row_0035CFC8;
typedef struct { u8 pad[0x184]; u8 *textures; } Tex_0035CFC8;
extern f32 D_L01_001DD6D4;
extern f32 D_001A4EC0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern Tex_0035CFC8 D_L01_00221098;
extern u8 *D_L01_0022116C;
static __inline__ u8 active_0035CFC8(Row_0035CFC8 *row) { return row->active; }
void func_L01_0035CFC8(u8 *m, s128 *from, s128 *to) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *,void *,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern s32 func_00382498(s32,s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_004713C8(void *,void *,s32,u32,s32,s32,s32,s32,f32,f32,f32);
    extern s32 func_00382468(s32);
    extern void func_003C4C18(void *,f32);
    extern u8 *func_L01_00465738(void *,void *,u32,s32,s32,s32,s32,s32,s32,f32);
    S_38C110v a,b,vel,pos,step,last;
    void *vars;
    f32 size,speed;
    s32 pieces;
    s32 i,tex,life,mode;
    u32 colour;
    u8 *p;
    u8 *origin;
    S_38C110v *pp;
    Row_0035CFC8 *rows;
    *(s128 *)&a=*from;
    vars=*(void **)(m+0x68);
    *(s128 *)&b=*to;
    if (!vars) return;
    size=D_L01_001DD6D4*210000.0f;
    speed=func_0038CEA8(vars);
    origin=m+0x10;
    pieces=(s32)(speed/0.1f);
    *(s128 *)&pos=*(s128 *)&b;
    step.x=a.x-b.x; step.y=a.y-b.y; step.z=a.z-b.z; step.w=a.w;
    func_0038CF68(&step,&step,speed/(f32)pieces);
    pp=&pos;
    rows=(Row_0035CFC8 *)D_L01_002C5600;
    for (i=9;i>=0;i--) {
        u32 c;
        tex=(s32)func_L01_00443A18(1.0f,3.0f);
        func_0038CE20(&vel,D_001A4EC0,-(func_003824E0(0.1f,0.3f)*0.020000001415610313f));
        life=func_00382498(6,12);
        if (func_0013D3E0()&2) {
            c=0x306fff;
            if (!active_0035CFC8(rows+D_001425C0[0x2f])) c=0xffff;
            mode=64;
        } else {
            c=0x2020ff;
            if (!active_0035CFC8(rows+D_001425C0[0x2f])) c=0x207f7f;
            mode=96;
        }
        p=func_L01_004713C8(pp,&vel,(life*5+2)/6,c,tex,mode,0,0,size,size*0.05f,0.0f);
        pos.x+=step.x; pos.y+=step.y; pos.z+=step.z;
        if (p) {
            p[2]=func_00382468(2) ? D_L01_00221098.textures[4] : D_L01_00221098.textures[5];
            p[3]=mode==64 ? 72 : 68;
        }
    }
    func_0038CE20(&last,vars,-0.040000002831220627f);
    func_003C4C18(&last,0.12000000476837158f);
    last.z+=0.06000000238418579f;
    colour=func_00382468(2) ? 0x7f407fff : 0x7f80dfff;
    life=func_00382498(8,17);
    p=func_L01_00465738(origin,&last,colour,255,life,0,-1,-1,0,94500.0f);
    if (p) {
        *(f32 *)(p+0x2c)=0.002400000113993883f;
        p[2]=*D_L01_0022116C;
    }
}
