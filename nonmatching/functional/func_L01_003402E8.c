/* functional: high. Not byte-exact; checked each branch/offset against the PAL asm. */
typedef struct { u8 pad0[0x10]; vu0_v4 pos; } Owner_003402E8;
extern s16 D_L01_001E18D0[];
extern s16 D_L01_001E18D8[];
extern vu0_v4 D_L01_00278E20[];
extern vu0_v4 D_L01_001E29C0[];
extern f32 D_001DD154_sda;
__asm__(".extern D_001DD154_sda, 4");
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);

void func_L01_003402E8(Owner_003402E8 *owner) {
    vu0_v4 pos, v10, v20, d[4];
    s32 i, j;
    s32 t;
    f32 sign;
    vu0_v4 *rec;

    pos = owner->pos;
    for (i = 0; i < 4; i++) {
        t = D_L01_001E18D0[i];
        if (t == 0) {
            continue;
        }
        t = (s16)(t - 1);
        if (t < 0) {
            t = 0;
        }
        D_L01_001E18D0[i] = t;
        rec = &D_L01_00278E20[i * 5];
        if (t == 0) {
            D_L01_001E18D0[i] = 4;
            D_L01_001E18D8[i] = 0x40;
            sign = 1.0f;
            func_00382580(&v10, D_001DD154_sda, D_001DD154_sda);
            rec[0] = pos;
            for (j = 0; j < 4; j++) {
                f32 ang;
                v20 = rec[j];
                v20.x -= D_L01_001E29C0[0].x; v20.y -= D_L01_001E29C0[0].y; v20.z -= D_L01_001E29C0[0].z;
                ang = func_003824E0(0.174532920f, 0.785398185f);
                func_0038D890(&v10, &v10, &v20, ang * sign);
                sign = -sign;
                rec[j + 1] = rec[j];
                rec[j + 1].x += v10.x; rec[j + 1].y += v10.y; rec[j + 1].z += v10.z;
            }
        } else {
            for (j = 0; j < 4; j++) {
                d[j] = rec[j + 1];
                d[j].x -= rec[j].x; d[j].y -= rec[j].y; d[j].z -= rec[j].z;
                d[j].x += func_L01_00443A18(0.0f, 0.1f);
                d[j].y += func_L01_00443A18(0.0f, 0.1f);
                d[j].z += func_L01_00443A18(0.0f, 0.1f);
            }
            rec[0] = pos;
            for (j = 0; j < 4; j++) {
                rec[j + 1] = rec[j];
                rec[j + 1].x += d[j].x; rec[j + 1].y += d[j].y; rec[j + 1].z += d[j].z;
            }
            if (D_L01_001E18D0[i] > 0) {
                D_L01_001E18D8[i] = 0x20;
            } else {
                D_L01_001E18D8[i] = 0;
            }
        }
    }
}
