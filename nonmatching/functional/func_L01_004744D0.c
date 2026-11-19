/* functional: high. Uses the file's raw VU0 asm style. */
/* localdecomp:start func_L01_004744D0 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_004744D0;
void func_L01_004744D0(u8 *p)
{
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_L01_004CAB30(void *,void *);
    V_004744D0 v;
    u8 *s=p+48;
    u8 *b,*a;
    f32 t;
    s32 alpha;
    if (func_0038CB00(p+10)) {func_003CD250(p);return;}
    if (*(s16 *)(p+10)<10) *(f32 *)(p+48)-=0.1f;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(v) : "m"(*(V_004744D0 *)(p+16)), "m"(*(V_004744D0 *)(p+32)) : "vf1","vf2");
    v.w=0;
    func_0038CF68(&v,&v,*(f32 *)(p+48));
    a=p+16;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(*(V_004744D0 *)(p+16)) : "m"(v) : "vf1","vf2");
    func_0038CF68(&v,&v,*(f32 *)(p+48));
    b=p+32;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(*(V_004744D0 *)(p+32)) : "m"(v) : "vf1","vf2");
    func_L01_004CAB30(a,a);
    func_L01_004CAB30(b,b);
    t=(f32)*(s16 *)(p+10)/(f32)*(s16 *)(s+12);
    *(f32 *)(p+28)=*(f32 *)(s+4)*(1.0f+(*(f32 *)(s+8)-1.0f)*t);
    if (*(s16 *)(p+10)<p[8]) {
        alpha=(s32)(((f32)*(s16 *)(p+10)/(f32)p[8])*127.0f)<<24;
        *(s32 *)(p+4)=alpha|(*(s32 *)(p+4)&0xFFFFFF);
        *(s32 *)(p+12)=alpha|(*(s32 *)(p+12)&0xFFFFFF);
    }
}
/* localdecomp:end func_L01_004744D0 */
