/* functional: high. Uses the file's raw VU0 asm style (file flags lack -mvu0-use-vf0-vf2). */
/* localdecomp:start func_L01_004730F8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_004730F8;
extern void func_L01_004CAB30(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004C7D98(void *, void *);
extern void func_003CD250(u8 *);

void func_L01_004730F8(u8 *obj) {
    V_004730F8 noise;
    u8 *state;
    u8 *pos;
    s32 brightness;
    u32 color;
    f32 strength;

    func_L01_004CAB30(obj + 0x10, obj + 0x10);
    state = obj + 0x20;
    if ((D_L01_002C5600 + D_001425D1[0])->level >= 4) {
        *(s32 *)(state + 0x10) -= 2;
    } else {
        *(s32 *)(state + 0x10) -= 1;
    }
    if (*(s32 *)(state + 0x10) < 0) {
        *(s32 *)(state + 0x10) = 0;
    }
    obj[8]++;
    pos = obj + 0x10;
    __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(*(V_004730F8 *)(obj + 0x10)) : "m"(*(V_004730F8 *)state) : "vf1", "vf2");
    *(f32 *)(obj + 0xC) += 1575.0f;
    func_0038CE20(state, state, 0.99f);
    func_L01_004C7D98(pos, &noise);
    brightness = obj[4];
    strength = -0.00075f;
    if (brightness < 32) {
        strength = 0.0015f;
    }
    func_0038CE20(&noise, &noise, strength);
    __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(*(V_004730F8 *)state) : "m"(noise) : "vf1", "vf2");
    color = *(u32 *)(obj + 4);
    color &= 0xFFFFFF;
    color = func_0038DBD8(color, 0, 0.025f);
    *(s32 *)(obj + 4) = color | (*(s32 *)(state + 0x10) << 24);
    if (*(s32 *)(state + 0x10) == 0) {
        func_003CD250(obj);
    }
}
/* localdecomp:end func_L01_004730F8 */
