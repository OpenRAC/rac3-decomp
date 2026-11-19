/* functional: high. Equal to retail after masking regs/addressing (90 diff words, scheduling). */
typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0xC];
} Pad_003A5238;
typedef struct {
    u8 pad00[0x10];
    vu0_v4 push;
    u8 *src;
    u8 pad24[8];
    f32 amount;
} Hit_003A5238;
extern Hit_003A5238 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C4A40(void *, void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L31_003A55A0(void *, s32);
extern void func_L31_003473F0(void *, f32, f32);
extern s32 D_001A71A0[];
extern f32 D_L31_001DE990;
extern f32 D_L31_001DE984;
extern f32 D_L31_001DE9DC;

/* Enemy/object hit reaction: takes damage from whatever hit it (a hit record from the collision
 * query), starts the hurt timer, knocks it back, and keeps its shadow/shake updated. */
void func_L31_003A5238(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    Hit_003A5238 *hit = func_L01_00447490(obj, 0x10000, 0);
    vu0_v4 push;
    f32 amount;

    func_0038CAD0(v + 0x174);
    func_L01_0044ABD0(obj, v + 0x40);
    if (hit != 0) {
        amount = hit->amount;
        if (0.0f < amount && obj[0x20] != 5) {
            if (obj[0x20] != 0x42 && *(s32 *)(v + 0x174) == 0) {
                if (hit->src != 0 && *(s16 *)(hit->src + 0xAA) == 0x15C6) {
                    *(f32 *)v = 0.0f;
                } else {
                    *(f32 *)v = *(f32 *)v - amount;
                }
                v[0x47] = 0xFF;
                *(s32 *)(v + 0x174) = 0xC;
                func_003C4A40(obj, v + 0x40);
                func_003A52A0(5, 0, obj);
                func_003A52A0(6, 0, obj);
                if (*(f32 *)v <= 0.0f) {
                    func_0038CF68(&push, &hit->push, D_L31_001DE990);
                    vec_add_ab(v + 0x160, v + 0x160, &push);
                    func_L31_003A55A0(obj, 5);
                } else {
                    if ((s32)hit->src == D_001A71A0[0]) {
                        func_0038CF68(&push, &hit->push, D_L31_001DE984);
                        vec_add_ab(v + 0x160, v + 0x160, &push);
                    }
                    func_L31_003A55A0(obj, 0xA);
                }
            }
        }
        obj[0xA8] = 0xFF;
    }
    if (obj[0x20] != 0x42 && obj[0x20] != 5) {
        func_L31_003473F0(obj + 0x10, D_L31_001DE9DC, D_L31_001DE9DC);
    }
}
