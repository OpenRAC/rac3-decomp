/* US draft of func_00386B10 (rac3-uya-decomp func_00386AE8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00386B10 */
typedef struct { u8 pad[0x140]; f32 x, y, z; } S_382458;
typedef struct { f32 x, y, z, w; u8 d[1][0x80]; } G_382458;
extern S_382458 D_002222C0;
extern G_382458 *D_001D9D44, *D_001D9D48, *D_001D9D4C;
extern u8 *D_001D9D60[2];
extern s32 D_001D9D58;
extern s32 D_001D9D50_00386B10;
extern s32 D_001D52F0;
extern u8 D_00227500[];
extern s32 D_00227480[];
extern void func_00386A58(s32, s32, s32, s32, s32, s32, f32);
extern void func_0038CF58();
extern void func_0038CF80();
extern void func_0038D130();
extern f32 func_0038D318();
extern f32 func_0038D540(f32, f32);

s32 func_00386B10(void) {
    f32 v[4];
    f32 d[4];
    s32 x = D_002222C0.x * 0.25f;
    s32 y = D_002222C0.y * 0.25f;
    s32 z = D_002222C0.z * 0.25f;
    u8 *r = (u8 *)func_00386980(x, y, z);
    if (r != 0) {
        D_001D9D58 = 0;
        func_0038D108(D_00227480, r, 0x80);
        D_001D9D60[D_001D52F0] = r;
    } else {
        D_001D9D58 = 1;
        if (D_001D9D50_00386B10 == 0) {
            s32 a = ((s32 (*)(s32, s32, s32, s32, s32, s32, f32))func_00386A58)(x - 1, y, z, x + 1, y, z, D_002222C0.x * 0.25f - x);
            s32 b = ((s32 (*)(s32, s32, s32, s32, s32, s32, f32))func_00386A58)(x, y - 1, z, x, y + 1, z, D_002222C0.y * 0.25f - y);
            s32 c = ((s32 (*)(s32, s32, s32, s32, s32, s32, f32))func_00386A58)(x, y, z - 1, x, y, z + 1, D_002222C0.z * 0.25f - z);
            if (a != 0 || b != 0 || c != 0) {
                func_0038CF80(D_00227500, 0x80);
                if (a != 0) func_0038D130(D_00227500, D_00227500, a, 0x80);
                if (b != 0) func_0038D130(D_00227500, D_00227500, b, 0x80);
                if (c != 0) func_0038D130(D_00227500, D_00227500, c, 0x80);
                r = D_00227500;
                D_001D9D60[D_001D52F0] = r;
                func_0038D108(D_00227480, r, 0x80);
            }
        }
        if (r == 0) {
            switch (D_001D9D50_00386B10) {
            case 2:
                if (D_001D9D44 != 0) {
                    G_382458 *p = D_001D9D44;
                    s32 a = D_002222C0.x - p->x > 0.0f;
                    s32 b = D_002222C0.y - p->y > 0.0f;
                    s32 c = D_002222C0.z - p->z > 0.0f;
                    func_0038D108(D_00227480, p->d[c + b * 2 + a * 4], 0x80);
                    break;
                }
                goto case0;
            case 3:
                if (D_001D9D48 != 0) {
                    s32 idx = 0;
                    v[0] = D_001D9D48->x;
                    v[1] = D_001D9D48->y;
                    v[2] = D_001D9D48->z;
                    v[3] = 0.0f;
                    d[0] = D_002222C0.x - v[0];
                    d[1] = D_002222C0.y - v[1];
                    d[2] = D_002222C0.z - v[2];
                    d[3] = 0.0f;
                    if (d[0] > 0.0f && d[1] > 0.0f) {
                        idx = (s32)(func_0038D540(d[0], d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = func_0038D318(&D_002222C0.x, v);
                    } else if (d[0] <= 0.0f && d[1] > 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_0038D540(d[1], 0.0f - d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = func_0038D318(D_00222400, v);
                        }
                    } else if (d[0] < 0.0f && d[1] < 0.0f) {
                        idx = (s32)(func_0038D540(0.0f - d[0], 0.0f - d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = 0.0f - func_0038D318(D_00222400, v);
                    } else if (d[0] >= 0.0f && d[1] < 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_0038D540(0.0f - d[1], d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = 0.0f - func_0038D318(D_00222400, v);
                        }
                    }
                    if (d[2] > 0.0f && d[0] > 0.0f) {
                        idx += (s32)(func_0038D540(d[2], d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] <= 0.0f && d[0] > 0.0f) {
                        idx += 0x10;
                        if (d[2] != 0.0f) idx += (s32)(func_0038D540(d[0], 0.0f - d[2]) * 32.0f / 3.1415927f);
                    } else if (d[2] < 0.0f && d[0] <= 0.0f) {
                        idx += 0x20;
                        if (d[0] != 0.0f) idx += (s32)(func_0038D540(0.0f - d[2], 0.0f - d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] >= 0.0f && d[0] < 0.0f) {
                        idx += 0x30;
                        if (d[2] != 0.0f) idx += (s32)(func_0038D540(0.0f - d[0], d[2]) * 32.0f / 3.1415927f);
                    }
                    func_0038D108(D_00227480, D_001D9D48->d[idx], 0x80);
                    break;
                }
            case0:
            case 0:
                if (D_001D9D60[D_001D52F0] != 0) {
                    func_0038D108(D_00227480, D_001D9D60[D_001D52F0], 0x80);
                    break;
                }
            case 1:
                func_0038CF58(D_00227480, -1, 0x80);
                break;
            case 4:
                if (D_001D9D4C != 0) {
                    s32 idx = 0;
                    v[0] = D_001D9D4C->x;
                    v[1] = D_001D9D4C->y;
                    v[2] = D_001D9D4C->z;
                    v[3] = 0.0f;
                    d[0] = D_002222C0.x - v[0];
                    d[1] = D_002222C0.y - v[1];
                    d[2] = D_002222C0.z - v[2];
                    d[3] = 0.0f;
                    if (d[0] > 0.0f && d[1] > 0.0f) {
                        idx = (s32)(func_0038D540(d[0], d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = func_0038D318(&D_002222C0.x, v);
                    } else if (d[0] <= 0.0f && d[1] > 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_0038D540(d[1], 0.0f - d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = func_0038D318(D_00222400, v);
                        }
                    } else if (d[0] < 0.0f && d[1] < 0.0f) {
                        idx = (s32)(func_0038D540(0.0f - d[0], 0.0f - d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = 0.0f - func_0038D318(D_00222400, v);
                    } else if (d[0] >= 0.0f && d[1] < 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_0038D540(0.0f - d[1], d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = 0.0f - func_0038D318(D_00222400, v);
                        }
                    }
                    if (d[2] > 0.0f && d[0] > 0.0f) {
                        idx += (s32)(func_0038D540(d[2], d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] <= 0.0f && d[0] > 0.0f) {
                        idx += 0x10;
                        if (d[2] != 0.0f) idx += (s32)(func_0038D540(d[0], 0.0f - d[2]) * 32.0f / 3.1415927f);
                    } else if (d[2] < 0.0f && d[0] <= 0.0f) {
                        idx += 0x20;
                        if (d[0] != 0.0f) idx += (s32)(func_0038D540(0.0f - d[2], 0.0f - d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] >= 0.0f && d[0] < 0.0f) {
                        idx += 0x30;
                        if (d[2] != 0.0f) idx += (s32)(func_0038D540(0.0f - d[0], d[2]) * 32.0f / 3.1415927f);
                    }
                    func_0038D108(D_00227480, D_001D9D4C->d[idx], 0x80);
                } else if (D_001D9D60[D_001D52F0] != 0) {
                    func_0038D108(D_00227480, D_001D9D60[D_001D52F0], 0x80);
                } else {
                    func_0038CF58(D_00227480, -1, 0x80);
                }
                break;
            }
        }
    }
    {
        u8 *q = (u8 *)D_00227480;
        q[0x7F] |= 0x80;
    }
}
/* localdecomp:end func_00386B10 */
