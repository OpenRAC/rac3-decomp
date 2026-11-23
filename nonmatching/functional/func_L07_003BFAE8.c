/* functional: high. near-miss (242 words, all FPR/GPR allocation) */
/* localdecomp:start func_L07_003BFAE8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003BFAE8;
typedef int Q_003BFAE8 __attribute__((mode(TI)));
extern f32 D_L07_002A2A90[];
extern f32 D_L07_002A2B50[];
extern u32 D_L07_001E16C8[];
void func_L07_003BFAE8(f32 t, f32 scale, u8 *self, u8 mode) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_003C4088(f32,f32,f32);
    extern void func_0038D750(void *,f32,s32);
    extern void func_0038D810(void *,void *);
    extern void func_0038D000(void *,void *,void *);
    extern void func_0038C750(void);
    extern s32 func_00389598(s32);
    extern void func_003A9440(s32,unsigned long);
    extern void func_003D3A24(s32,void *,void *,void *,s32);
    V_003BFAE8 rot;
    V_003BFAE8 mat[3];
    V_003BFAE8 offset;
    V_003BFAE8 radial;
    V_003BFAE8 temp;
    u8 *original = self;
    f32 radius,angle,a,b,c,d,e,phase,sign,position,fade,height,negativeHeight;
    u32 color;
    s32 i;
    f32 *vertices;
    f32 *uv;
    u32 *colors;
    f32 s,blend;
    blend = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f;
    height = func_003C4088(12.0f,8.0f,t) * scale;
    a = func_003C4088(1.8f,1.0f,t);
    position = 0.0f;
    b = func_003C4088(3.0f,6.0f,t);
    c = func_003C4088(1.5707964f,1.3089969f,blend);
    d = func_003C4088(1.5707964f,0.0f,blend);
    e = func_003C4088(-0.5f,4.0f,t);
    if (t < 0.5f) color = ((s32)((t+t)*128.0f) << 24) | 0x808080;
    else color = ((s32)(((1.0f-t)*2.0f)*128.0f) << 24) | 0x808080;
    phase = (t*2.3f*t*2.0f) - (f32)(s32)(t*2.3f*t*2.0f);
    sign = 1.0f;
    if (mode) sign = -1.0f;
    negativeHeight = -height;
    vertices = D_L07_002A2A90;
    uv = D_L07_002A2B50;
    colors = D_L07_001E16C8;
    for (i=0;i<8;i++) {
        func_0038D750(&rot,*(f32 *)(self+0xF8),2);
        func_0038D810(&rot,mat);
        s = 1.0f-func_0038D098(position*3.1415927f);
        s *= 0.5f;
        radius = func_003C4088(a,b,s);
        angle = func_003C4088(c,d,s);
        fade = func_003C4088(0.12f,e,position);
        *(Q_003BFAE8 *)&offset = 0;
        offset.x = negativeHeight * position;
        offset.y = sign * fade;
        func_0038D000(&offset,&offset,mat);
        *(Q_003BFAE8 *)&temp = 0;
        temp.y = sign * radius * func_0038D098(angle);
        temp.z = radius * func_0038D0B0(angle);
        radial = temp;
        func_0038D000(&radial,&radial,mat);
        __asm__("lqc2 $vf2,%2
	lqc2 $vf1,%1
	vadd.xyz $vf1,$vf1,$vf2
	sqc2 $vf1,%0"
          : "=m"(temp) : "m"(*(V_003BFAE8 *)(original+0x10)), "m"(offset) : "vf1","vf2");
        uv[1] = 1.0f;
        {
            f32 x=temp.x,y=temp.y,z=temp.z;
            __asm__("lqc2 $vf2,%1
	lqc2 $vf1,%2
	vadd.xyz $vf2,$vf2,$vf1
	sqc2 $vf2,%0"
              : "=m"(temp) : "m"(temp),"m"(radial) : "vf1","vf2");
            vertices[0]=x;vertices[1]=y;vertices[2]=z;
        }
        vertices[3]=temp.x;vertices[4]=temp.y;vertices[5]=temp.z;
        uv[2]=uv[0]=s*2.3f-phase;
        uv[3]=0.0f;
        if (i==0 || i==7) colors[0]=0x808080;
        else colors[0]=color;
        colors[1]=0x808080;
        if (**(u8 ***)(self+0x68)) {
            self=**(u8 ***)(self+0x68);
            position=0.0f;
        } else position+=0.16666667f;
        colors+=2;uv+=4;vertices+=6;
    }
    func_0038C750();
    func_003A9440(6,func_00389598(0x65));
    func_003A9440(8,4);
    func_003A9440(0x42,0x8000000044UL);
    func_003D3A24(16,D_L07_002A2A90,D_L07_001E16C8,D_L07_002A2B50,1);
}
/* localdecomp:end func_L07_003BFAE8 */
