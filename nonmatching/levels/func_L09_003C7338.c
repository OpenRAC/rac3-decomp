/* func_L09_003C7338: near miss (Sonnet w4 p2w3): NEAR 0
   Size 560 bytes. MATCH at all 5 PAL places (09,18,20,24,29) but only with --as ps2as; file L09_003C5E78.c has C compiled without @ps2as, so lead must decide (flag is per file); NTSC-U differs
   Left for lead: see note.
*/
typedef struct {
    char pad00[0x140];
    f32 position[4];
} Cam09;
extern Cam09 D_L09_001E29C0;
extern u8 *D_L09_00220184[];
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, s32, s32);
extern s32 func_00382498(s32, s32);

void func_L09_003C7338(u8 *object, s32 joint, s32 unused, f32 radius) {
    f32 initial[4], point[4], velocity[4];
    f32 heading, speed, tilt, yaw;
    u8 *particle;
    u8 *data;
    func_003C2F58(object, joint, initial);
    heading = func_0038D160(D_L09_001E29C0.position[0] - *(f32 *)(object + 0x10),
                            D_L09_001E29C0.position[1] - *(f32 *)(object + 0x14));
    point[0] = initial[0] + func_L01_00443A18(0.0f, radius);
    point[1] = initial[1] + func_L01_00443A18(0.0f, radius);
    point[2] = initial[2] + func_L01_00443A18(0.0f, radius);
    speed = func_003824E0(radius * 0.5f * 0.020000001f, radius * 0.020000001f);
    tilt = func_L01_00443A18(0.0f, 1.3962634f);
    yaw = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.5707964f));
    func_00382760(velocity, speed, yaw, tilt);
    particle = func_L01_004669B0(0.0f, 1.0f, 1.01f, radius * 210000.0f, point, -1, velocity, 0x306F6FAF, 0);
    if (particle != 0) {
        particle[3] = 0x48;
        *(s16 *)(particle + 0xA) = (func_00382498(40, 70) * 5 + 2) / 6;
        particle[9] = 100;
        data = particle + 0x20;
        *(f32 *)(data + 0x1C) = (f32)((func_00382498(1, 10) * 5 + 2) / 6);
        *(s32 *)(data + 4) = 3;
        data[0xA] = 0x7F;
        data[0xB] = particle[0xA];
        particle[2] = *D_L09_00220184[0];
    }
}
