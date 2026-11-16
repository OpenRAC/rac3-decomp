#include "common.h"

/* NTSC-U counterpart of func_L21_003B1F10 (src/levels/21_obani_draco/L21_003B1A00.c) */
#include "vu0.h"
extern f32 func_0037E250(f32, f32);
typedef struct {
    f32 w[0x1C];
    f32 h70;
    void *owner;
    s16 h78;
    s16 h7A;
    f32 h7C;
} S_003B1A00;

/* localdecomp:start func_L21_003B0358 */
typedef struct {
    vu0_v4 m[4];
    s32 col[4];
    f32 uv[8];
    long x70, x78, x80, x88;
} __attribute__((aligned(16))) Q_003B1F10;

extern s32 D_L21_001DE940;
extern f32 func_L01_0040CFE8(f32, f32);
extern void func_00388BF0(void *, void *);
extern long func_00384EC0(s32);
extern f32 func_00389410(f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003CD830(void *, void *, s32);
extern s32 func_003894A0(s32, s32, f32);
extern f32 func_0037E250(f32, f32);

void func_L21_003B0358(u8 *arg0) {
    Q_003B1F10 q;
    vu0_v4 mtx[4];
    vu0_v4 rot;
    S_003B1A00 *s;
    f32 r;
    f32 scroll;
    f32 p0, p1;
    f32 y0, y1;
    f32 amp;
    f32 a;
    f32 lat0, lat1, lat, tilt, prevLat, prevTilt;
    s32 c0, c1;
    s32 i, j, k, m;

    s = *(S_003B1A00 **)(arg0 + 0x68);
    r = s->h70 * (f32)s->h7A;
    scroll = func_L01_0040CFE8((f32)D_L21_001DE940, 30.0f) / 30.0f;
    rot = *(vu0_v4 *)(arg0 + 0xF0);
    rot.x = 0.0f;
    func_00388BF0(mtx, &rot);
    mtx[3] = *(vu0_v4 *)(arg0 + 0x10);
    q.x78 = func_00384EC0(0xE);
    q.x80 = 0xFF9000000260L;
    q.x88 = 0x8000000048L;
    q.x70 = 0;
    for (i = 0; i < 5; i++) {
        p0 = (f32)i * 0.06981317f / 5.0f - 0.034906585f;
        p1 = (f32)(i + 1) * 0.06981317f / 5.0f - 0.034906585f;
        for (j = 0; j < 10; j++) {
            y0 = func_00389410((f32)j * 1.3962634f / 10.0f) - 0.6981317f;
            y1 = func_00389410((f32)(j + 1) * 1.3962634f / 10.0f) - 0.6981317f;
            q.uv[0] = scroll + (func_00388960(y0) + 1.0f) * 0.5f;
            q.uv[2] = scroll + (func_00388960(y1) + 1.0f) * 0.5f;
            q.uv[4] = scroll + (func_00388960(y0) + 1.0f) * 0.5f;
            q.uv[6] = scroll + (func_00388960(y1) + 1.0f) * 0.5f;
            q.uv[1] = (func_00388978(p0) + 1.0f) * 0.5f;
            q.uv[3] = (func_00388978(p0) + 1.0f) * 0.5f;
            q.uv[5] = (func_00388978(p1) + 1.0f) * 0.5f;
            q.uv[7] = (func_00388978(p1) + 1.0f) * 0.5f;
            if (s->h78 != 0) {
                amp = (f32)s->h78 / 15.0f * 64.0f;
            } else {
                amp = 64.0f;
            }
            c0 = (s32)(amp * func_00388978((f32)i * 3.1415927f / 5.0f));
            c1 = (s32)(amp * func_00388978((f32)(i + 1) * 3.1415927f / 5.0f));
            q.col[0] = j != 0 ? (c0 << 24) | 0x320078 : 0x320078;
            q.col[1] = j != 9 ? (c0 << 24) | 0x320078 : 0x320078;
            q.col[2] = j != 0 ? (c1 << 24) | 0x320078 : 0x320078;
            q.col[3] = j != 9 ? (c1 << 24) | 0x320078 : 0x320078;
            func_0037E4B8(&q.m[0], r, y0, p0);
            func_0037E4B8(&q.m[1], r, y1, p0);
            func_0037E4B8(&q.m[2], r, y0, p1);
            func_0037E4B8(&q.m[3], r, y1, p1);
            q.m[0].w = 1.0f;
            q.m[1].w = 1.0f;
            q.m[2].w = 1.0f;
            q.m[3].w = 1.0f;
            func_003CD830(&q, mtx, 0);
        }
    }
    q.x78 = func_00384EC0(0x38);
    for (k = 0; k < 3; k++) {
        prevTilt = prevLat = 0.0f;
        for (m = 0; m < 28; m++) {
            lat0 = func_00389410((f32)m * 1.3962634f / 28.0f) - 0.6981317f;
            lat1 = func_00389410((f32)(m + 1) * 1.3962634f / 28.0f) - 0.6981317f;
            lat = func_0037E250(lat0, lat1);
            if (m == 0) {
                prevLat = lat0;
            } else if (m == 27) {
                lat = lat1;
            }
            q.uv[1] = 0.0f;
            q.uv[3] = 0.0f;
            q.uv[5] = 1.0f;
            q.uv[7] = 1.0f;
            q.uv[0] = (f32)m / 28.0f;
            q.uv[4] = (f32)m / 28.0f;
            q.uv[2] = (f32)(m + 1) / 28.0f;
            q.uv[6] = (f32)(m + 1) / 28.0f;
            if (s->h78 != 0) {
                a = q.uv[5] - (f32)s->h78 / 15.0f;
            } else {
                a = q.uv[1];
            }
            if (a < 0.0f) {
                a = 0.0f;
            }
            q.col[0] = q.col[1] = q.col[2] = q.col[3] = func_003894A0(0xFF701050, 0xFF0000, a);
            tilt = s->w[m] * 0.017453292f * func_0037E250(-1.0f, 1.0f) * (f32)s->h7A * 3.0f;
            if (0.027925268f < tilt) {
                tilt = 0.027925268f;
            }
            if (tilt < -0.027925268f) {
                tilt = -0.027925268f;
            }
            if (m == 0) {
                prevTilt = 0.0f;
            }
            func_0037E4B8(&q.m[0], r, prevLat, prevTilt);
            func_0037E4B8(&q.m[1], r, lat, tilt);
            func_0037E4B8(&q.m[2], r, prevLat, prevTilt);
            func_0037E4B8(&q.m[3], r, lat, tilt);
            prevTilt = tilt;
            prevLat = lat;
            q.m[2].z -= 0.15f;
            q.m[3].z -= 0.15f;
            q.m[0].w = 1.0f;
            q.m[1].w = 1.0f;
            q.m[2].w = 1.0f;
            q.m[3].w = 1.0f;
            func_003CD830(&q, mtx, 0);
        }
    }
}
/* localdecomp:end func_L21_003B0358 */
