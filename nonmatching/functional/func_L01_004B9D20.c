/* functional: high. Level (re)initialisation after a respawn/reload: resets camera/hero scratch state, copies the level's colour/light block, frees the object slots, re-seats the hero and camera onto the ground and calls the pending callback. Ported from the NTSC-U draft with PAL's names, constants (12.0f, 0x19) and addresses re-read against the PAL asm; store-in-delay-slot orders kept before the call. */
typedef struct {
    u8 pad0[0xC];
    u8 b0C;
    u8 pad0D[0x3B];
    s32 w48[1];
} Slot_004B9D20;

typedef struct {
    u8 pad0[0x24];
    Slot_004B9D20 *p24;
    u8 pad28[0x40];
    s32 w68;
} Ent_004B9D20;

extern s32 D_L01_001D6720;
extern f32 D_L01_001DF9F4_sda;
extern f32 D_L01_001E7630;
extern u8 *D_L01_001DFC18;
extern void *D_L01_001DFC1C;
extern void (*D_L01_001D6724)(void *);
extern void *D_L01_001D6728_sda;
extern s32 D_L01_001EA820;
extern s32 D_L01_001D6690_sda;

extern void func_0038A238(s32);
extern void func_L01_00460248(void);
extern void func_L01_00460200(f32);
extern void func_003A9050(void);
extern void func_L01_0042C370(void);
extern void func_L01_003F5498(s32, f32);
extern void func_003E5520(void);
extern void func_003864C0(s32);
extern void func_003873C0(void);
extern void func_003C2880(void *);
extern void func_L01_004B9798(s32);
extern void func_L01_00504E38(s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00510AD0(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_004602C0(void *, void *, s32);
extern void func_L01_0045F380(s32);
extern void func_L01_004AC8A8(void);

void func_L01_004B9D20(void) {
    u8 *g = (u8 *)&D_L01_001E6D80;
    u8 *h = (u8 *)&D_001A4BE0;
    s32 i;
    f32 f;
    f32 d;

    if (D_L01_001DF950[0] < 0.5f) {
        func_0038A238(8);
    } else {
        func_0038A238(2);
    }
    if (D_001CCFD0.h76 != 6 && D_001CCFD0.h76 != 7) {
        D_001CCFD0.h76 = 5;
    }
    if (D_001CCFD0.h9E != 6 && D_001CCFD0.h9E != 7) {
        D_001CCFD0.h9E = 5;
    }
    func_L01_00460248();
    func_L01_00460200(1.0f);
    func_003A9050();
    func_L01_0042C370();
    D_L01_001DF95C = 0;
    D_L01_001DF960 = 0;
    D_L01_001DF958[0] = 0;
    D_L01_001D6720 = 0;
    func_L01_003F5498(0, 12.0f);
    func_003E5520();
    D_L01_001DF9E4 = *(u8 *)(g + 0x70);
    D_L01_001DF9E5 = *(u8 *)(g + 0x74);
    D_L01_001DF9E6 = *(u8 *)(g + 0x78);
    D_L01_001DF9E8 = *(f32 *)(g + 0x80);
    D_L01_001DF9EC = *(f32 *)(g + 0x84);
    D_L01_001DF9F0 = *(f32 *)(g + 0x88);
    D_L01_001DF9F4_sda = *(f32 *)(g + 0x8C);
    func_003864C0(0);
    D_L01_001E7630 = 0.62f;
    func_003873C0();
    for (i = 0; i < *(s16 *)(g + 0x44); i++) {
        Ent_004B9D20 *e = ((Ent_004B9D20 **)(g + 0x1A0))[i];
        if (e != 0) {
            e->p24->b0C -= 1;
            e->p24->w48[e->p24->b0C] = 0;
            e->w68 = 0;
            func_003C2880(e);
            ((Ent_004B9D20 **)(g + 0x1A0))[i] = 0;
        }
    }
    func_L01_004B9798(0);
    if (D_001A4BE0.w25C0 != 0) {
        func_L01_00504E38(1);
        f = func_003C3D30((f32 *)(h + 0x80), 0, 0, 0.5f);
        if (f > 2.0f) {
            d = *(f32 *)(h + 0x88) - f;
            if (d < 0.0f) {
                d = -d;
            }
            if (d < 4.5f) {
                *(f32 *)(h + 0x88) = f;
            }
        }
        *(u8 *)(h + 0x25E5) = 0;
        func_L01_00510AD0();
        if (*(s16 *)(g + 0x46) != 0) {
            f = func_003C3D30((f32 *)(g + 0x10), 0, 0, 0.5f);
            if (f > 2.0f) {
                d = *(f32 *)(g + 0x18) - f;
                if (d < 0.0f) {
                    d = -d;
                }
                if (d < 2.0f) {
                    *(f32 *)(g + 0x18) = f;
                }
            }
            func_L01_004F50C8(g + 0x10, g + 0x20, 0, 1);
        }
    }
    if (D_L01_001DFC18 != 0) {
        *(u16 *)(D_L01_001DFC18 + 0x34) &= 0xFFFE;
        if (D_L01_001DFC18 != 0) {
            u8 *p = D_L01_001DFC18;
            void *q = D_L01_001DFC1C;
            D_L01_001DFC18 = 0;
            D_L01_001DFC1C = 0;
            func_L01_004602C0(p, q, 1);
        }
    }
    func_L01_0045F380(0x19);
    if (D_L01_001D6724 != 0 && D_L01_001EA820 == 0 && D_L01_001D6690_sda != 2 &&
        D_L01_001D6690_sda != 1) {
        D_L01_001D6724(D_L01_001D6728_sda);
        D_L01_001D6724 = 0;
        D_L01_001D6728_sda = 0;
    }
    func_L01_004AC8A8();
}
