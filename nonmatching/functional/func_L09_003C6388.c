/* functional: high. Rewritten from the PAL assembly (NTSC draft differs: frame counter % 37, cooldown 8, scale 0.6f, other globals/callees); VU0 xyz subs as plain float ops. Compiles at level 09, same stack (0xA0); diffs are scheduling. Switch-free; D_001A4CC0+0x24E4 is the game-mode word the draft names as .state. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C6388;
extern s32 D_L09_001DFBC0;
extern s32 D_001D545C;
extern f32 D_L09_001DA9F0;
extern u8 D_0014275B[];
extern f32 D_L09_002F1D50[];
extern V4_003C6388 D_001A4CC0;
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L01_004E9980(void *, f32, f32, f32, f32, s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CB00(void *);
extern u8 *func_00382348(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D098(f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_0041A4F0(void);
extern void func_003A52A0(s32, s32, void *);
extern void func_L09_003DF890(void *, void *, void *, f32, s32);
extern void func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern void func_0038D750(void *, s32, f32);

void func_L09_003C6388(u8 *m) {
    V4_003C6388 temp, direction, origin, target;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *a, *b, *extra, *extra2;
    f32 yaw, accel, speed, limit, shot, turn, da, db;

    if (*(s32 *)(p + 0x758) == -1) {
        return;
    }
    if (D_L09_001DFBC0 % 37 == 0) {
        temp = D_001A4CC0;
        func_003C2F58(m, *(s16 *)(p + 0x762) ? 18 : 17, &origin);
        D_001A4CC0 = origin;
        if (*(s32 *)((u8 *)&D_001A4CC0 + 0x24E4) == 49) {
            a = func_L01_004E9980(&target, 18.0f, *(f32 *)(m + 0xF8), 2.3561945f, 0.5f, 5, 1);
            b = func_L01_004E9980(&target, 30.0f, *(f32 *)(p + 0x724), 2.3561945f, 0.5f, 5, 1);
            if (a == 0) {
                *(u8 **)(p + 0x75C) = b;
            } else if (b == 0) {
                *(u8 **)(p + 0x75C) = a;
            } else {
                db = func_L01_0040E570(&origin, b + 0x10);
                da = func_L01_0040E570(&origin, a + 0x10);
                if (da < db) {
                    *(u8 **)(p + 0x75C) = a;
                } else {
                    *(u8 **)(p + 0x75C) = b;
                }
            }
        } else {
            *(u8 **)(p + 0x75C) = func_L01_004E9980(&target, 30.0f, *(f32 *)(p + 0x724), 2.3561945f, 0.5f, 5, 1);
        }
        D_001A4CC0 = temp;
    }
    func_0038CB00(p + 0x716);
    if (*(u8 **)(p + 0x75C) != 0) {
        u8 *o = *(u8 **)(p + 0x75C);
        temp = *(V4_003C6388 *)(o + 0x10);
        temp.x = *(f32 *)(o + 0x10) - *(f32 *)(m + 0x10);
        temp.y = *(f32 *)(o + 0x14) - *(f32 *)(m + 0x14);
        temp.z = *(f32 *)(o + 0x18) - *(f32 *)(m + 0x18);
        extra = func_00382348(*(u8 **)(p + 0x75C));
        if (extra != 0) {
            temp.z += *(f32 *)(extra + 0x10);
        }
        yaw = func_0038D160(temp.x, temp.y);
        if (func_0038CEA8(&temp) > 30.0f) {
            *(u8 **)(p + 0x75C) = 0;
        }
        accel = 2000.0f;
        speed = 3000.0f;
        limit = 300.0f;
        *(f32 *)(p + 0x764) = yaw;
        if (*(s16 *)(p + 0x716) <= 0 && *(u8 **)(p + 0x75C) != 0) {
            func_003C2F58(m, *(s16 *)(p + 0x762) ? 18 : 17, &origin);
            extra2 = func_00382348(*(u8 **)(p + 0x75C));
            target = *(V4_003C6388 *)(*(u8 **)(p + 0x75C) + 0x10);
            if (extra2 != 0) {
                target.z += *(f32 *)(extra2 + 0x10);
            }
            direction = target;
            direction.x = target.x - origin.x;
            direction.y = target.y - origin.y;
            direction.z = target.z - origin.z;
            func_0038CF68(&direction, &direction, 0.6f);
            shot = 10.0f;
            if (func_L01_0041A4F0() != 0) {
                if (D_001D545C == 7 && D_0014275B[0] != 0) {
                    shot = D_L09_001DA9F0 * shot;
                } else {
                    shot = D_L09_002F1D50[D_001D545C] * shot;
                }
            }
            func_003A52A0(3, 0, m);
            func_L09_003DF890(m, &origin, &direction, shot, 0x10000);
            *(s16 *)(p + 0x716) = 8;
            *(u8 *)(p + 0x7AE) = 1;
            *(u16 *)(p + 0x762) ^= 1;
        }
    } else {
        accel = 200.0f;
        speed = 5000.0f;
        limit = 60.0f;
        *(s16 *)(p + 0x760) = *(s16 *)(p + 0x760) - 1;
        if (*(s16 *)(p + 0x760) <= 0) {
            turn = func_003824E0(-1.5707964f, 1.5707964f);
            if (turn > -0.5f && turn <= 0.0f) {
                turn = -0.5f;
            } else if (turn < 0.5f && turn > 0.0f) {
                turn = 0.5f;
            }
            *(f32 *)(p + 0x764) = func_0038DAB8(*(f32 *)(p + 0x764), turn);
            *(s16 *)(p + 0x760) = (func_00382498(30, 300) * 5 + 2) / 6;
        }
        *(f32 *)(p + 0x770) = func_0038DAB8(*(f32 *)(p + 0x770), 0.06981318f);
        *(f32 *)(p + 0x764) += func_0038D098(*(f32 *)(p + 0x770)) * 0.019f;
    }
    func_L01_00448728(p + 0x724, *(f32 *)(p + 0x764), p + 0x76C,
                      (accel * 0.017453292f) * 0.00040000002f,
                      (speed * 0.017453292f) * 0.00040000002f,
                      (limit * 0.017453292f) * 0.020000001f, 0);
    yaw = func_0038DB00(*(f32 *)(p + 0x724), *(f32 *)(m + 0xF8));
    func_0038D750(p + 0x570, 2, yaw);
}
