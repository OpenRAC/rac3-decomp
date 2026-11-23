/* functional: high. 13 diff vs retail; every branch, offset and VU0 operand order checked vs asm */
/* localdecomp:start func_L01_003E4198 */
extern u128_t D_L01_001EAA20;
s32 func_L01_003E4198(u8 *obj, u128_t *out, s32 force) {
    extern void func_L01_003E4028(u8 *, u128_t *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    struct {u128_t base, start, end, tmp;} v;
    u8 *hero=obj+0x150;
    f32 dist;
    if (*(s16 *)(hero+0x120)==0) {
        func_L01_003E4028(*(u8 **)(obj+0x50),out);
        return 1;
    }
    func_L01_003E4028(*(u8 **)(obj+0x50),&v.base);
    dist=*(f32 *)(hero+0x114);
    if (dist>=30.0f || force==0) {
        func_0038CE20(&v.tmp,obj+0x90,0.2f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
           : "=m"(v.start) : "m"(v.tmp),"m"(v.base) : "vf1","vf2");
        func_0038CE20(&v.tmp,obj+0x90,-30.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
           : "=m"(v.end) : "m"(v.base),"m"(v.tmp) : "vf1","vf2");
        if (func_003D3CB0(&v.start,&v.end,18,*(void **)(hero+0xF0),0)) {
            *out=D_L01_001EAA20;
            return 0;
        } else {
            *out=v.base;
            return -1;
        }
    } else {
        func_0038CE20(&v.start,obj+0x90,-dist);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
           : "=m"(*out) : "m"(v.base),"m"(v.start) : "vf1","vf2");
        return 1;
    }
}
/* localdecomp:v.end func_L01_003E4198 */
