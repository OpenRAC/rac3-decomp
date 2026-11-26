#include "common.h"
/* func_L39_005DC648 (k4 Sonnet first pass, 3088 B, 15 places): NEAR, check says 300+ diff rows but an LCS alignment of
 * retail vs this C matches 699 of 773 instructions (90%); place 39 only, other places not checked.
 * Flags: file's own (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as).
 * Equal: prologue incl. the four f20-f23 saves, every call sequence and argument, all three do/while build loops,
 *   the final func_003E8630 link loops, epilogue. (Floats are f32 literals 0.5/0.52/0.8/0.7/0.9/0.14/0.05/0.062000003/
 *   0.075/0.093/0.002/0.035/0.0434.)
 * Differs (all register-number or scheduling, no structural diff left):
 *   (1) the constant 1 stored to D_002438EC (u8) sits in $v1 in retail, $v0 here; the second func_L39_005DBEE8 call
 *       sets $a2 before $a1 in retail.
 *   (2) colour words (5 reads of the 4-byte colour structs D_0049A018/A008/A010/99FF0/99FF8, {r,g,b,a} as
 *       (a<<24)|(b<<16)|(g<<8)|r): retail issues all three sll first, then the ors; base register is $a1 not $v0.
 *       The structs must be >8 bytes (declared with 12 bytes of padding) to get the shared lui/addiu base like retail.
 *   (3) `if (D_0024CD50.f4 == 0) g = func_003E6C08(&D)`: retail keeps &D in $a0 and g in $v0 (delay-slot move);
 *       here the address lives in $v0. Tried a local pointer and a ternary: same.
 *   (4) `D_00352940.f20C->fNN` loads: retail puts f20C in $v1 and the field in $v0; here the reverse. Same cause as (1).
 * Prototypes (inferred): func_L01_00516470/00517538/00516728(s32, f32, f32), func_L01_005170B8(s32, u32 colour),
 *   func_L01_00516AA0/00516C78(s32, s32, s32), func_L39_005DC4C0 is passed f32 locals through (s32 *) casts (retail reads
 *   them with lwc1). func_L39_00602240 is called with one argument 0 (its catalogue C declares (void)). The object returned
 *   by func_003E6378 gets a null-check then ->f50 is written even when null (retail does that too).
 *   Callee names are catalogue names of the same addresses (func_003B43B0=0x5DBBC0, func_003E51F8=0x5D7AB0, ...).
 * Next: try declaring the colour reads as u8 [4] with the struct pad variants or a union to change the sll scheduling,
 *   a local for D_00352940.f20C (pointer register numbering), check the other 14 places once place 39 matches. */
/* localdecomp:start func_L39_005DC648 */
typedef struct {
    u8 p0[0x40]; s32 f40; s32 f44; u8 p48[0x18]; s32 f60[8]; u8 p80[8]; s32 f88; s32 f8C;
} S_005DC648_inner;
typedef struct { u8 p0[0x20C]; S_005DC648_inner *f20C; } S_005DC648_t;
typedef struct { u8 p0[8]; struct { u8 p0[0x10]; s32 (*f10)(void *, s32); } *f8; u8 p0C[0x44]; s32 f50; } S_005DC648_obj;
typedef struct { u8 p0[4]; s32 f4; u8 p8[8]; } S_005DC648_g;
typedef struct { u8 r, g, b, a; u8 pad[12]; } S_005DC648_c;

extern S_005DC648_t D_L39_00352940;
extern S_005DC648_g D_L39_0024CD50;
extern S_005DC648_c D_L39_0049A018;
extern S_005DC648_c D_L39_0049A008;
extern S_005DC648_c D_L39_0049A010;
extern S_005DC648_c D_L39_00499FF0;
extern S_005DC648_c D_L39_00499FF8;
extern u8 D_L39_002438EC;
extern s32 D_L39_00245D00;

extern s32 func_003B43B0(s32);
extern void func_L39_005DBEE8(s32, s32, s32);
extern s32 func_L39_00602240(s32);
extern void func_L01_004D2110(s32);
extern void func_L01_00518D40(s32);
extern void func_003B5060(s32);
extern void func_003E51F8(s32);
extern void func_003E5360(s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_005170B8(s32, u32);
extern void func_L01_00517538(s32, f32, f32);
extern s32 *func_003E6C08(void *);
extern void *func_003E6DE8(void *);
extern S_005DC648_obj *func_003E6378(void *, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516FD8(s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00516728(s32, f32, f32);
extern void func_L01_00516C78(s32, s32, s32);
extern void func_L01_005168F0(s32, f32);
extern void func_003E6FF0(s32, s32);
extern void func_003E8630(s32, s32);
extern void func_003E8348(s32, s32);
extern f32 func_L39_005DD390(s32);
extern s32 func_L39_005DC4C0(s32, s32 *, s32 *);
extern void func_L39_005DBF90(s32);

void func_L39_005DC648(s32 arg0) {
    f32 x0, y0, x1, y1, x2, y2;
    S_005DC648_obj *o;
    void *g;
    s32 i;

    func_L39_005DBEE8(func_003B43B0(0), func_L39_00602240(0), 0);
    D_L39_002438EC = 1;
    func_L01_004D2110(1);
    func_L39_005DBEE8(func_003B43B0(0), func_L39_00602240(0), 0);
    func_L01_00518D40(0x50000);
    func_003B5060(0x50001);
    func_003B5060(0x50002);
    func_003B5060(0x50003);
    func_003B5060(0x50004);
    func_003B5060(0x50005);
    func_003E51F8(0x50006);
    func_003E51F8(0x50007);
    func_003E51F8(0x50009);
    func_003E51F8(0x5000A);
    func_003E51F8(0x5000B);
    func_003E51F8(0x5000C);
    func_003E51F8(0x5000D);
    func_003E51F8(0x5000E);
    func_003E51F8(0x5000F);
    func_003E51F8(0x50010);
    func_003E51F8(0x50011);
    func_003E51F8(0x50012);
    func_003E51F8(0x50008);
    func_003E51F8(0x50013);
    func_003E51F8(0x50014);
    func_003E51F8(0x50015);
    func_003E51F8(0x50016);
    func_003E51F8(0x50017);
    func_003E51F8(0x50018);
    func_003E51F8(0x50019);
    func_003E51F8(0x5001A);
    func_003E51F8(0x5001B);
    func_003E51F8(0x5001C);
    func_003E51F8(0x5001D);
    func_003E51F8(0x5001E);
    func_003E51F8(0x5001F);
    func_003E51F8(0x50020);
    func_003E51F8(0x50021);
    func_003E51F8(0x50022);
    func_003E5360(0x50023);
    func_003E5360(0x50024);
    func_L01_00516470(0x50006, 0.5f, 0.52f);
    func_L01_005170B8(0x50006, (D_L39_0049A018.a << 24) | (D_L39_0049A018.b << 16) | (D_L39_0049A018.g << 8) | D_L39_0049A018.r);
    func_L01_00517538(0x50006, 0.8f, 0.7f);
    g = &D_L39_0024CD50;
    if (D_L39_0024CD50.f4 == 0) {
        g = func_003E6C08(&D_L39_0024CD50);
    }
    o = func_003E6378(func_003E6DE8(g), 0x50006);
    if (o == 0 || o->f8->f10(o, D_L39_00245D00) == 0) {
        o = 0;
    }
    o->f50 = func_003B43B0(0);
    func_L01_00517190(0x50006, 1);
    func_L01_00516FD8(0x50023, func_00381FF0(0x12A5));
    func_L01_00516FD8(0x50024, func_00381FF0(0x12A6));
    func_L01_005170B8(0x50023, 0x8066CCFF);
    func_L01_005170B8(0x50024, 0x8066CCFF);
    func_L01_00516470(0x50023, 0.5f, 0.9f);
    func_L01_00516470(0x50024, 0.5f, 0.14f);
    func_L01_00516AA0(0x50023, 1, 0);
    func_L01_00516AA0(0x50024, 1, 0);
    func_L01_00516AA0(0x50023, 0x40, 1);
    func_L01_00516AA0(0x50024, 0x40, 1);
    func_L01_00516470(0x50007, 0.0f, 0.0f);
    func_L01_005170B8(0x50007, (D_L39_0049A008.a << 24) | (D_L39_0049A008.b << 16) | (D_L39_0049A008.g << 8) | D_L39_0049A008.r);
    func_L01_00517538(0x50007, 0.075f, 0.093f);
    func_L01_00517190(0x50007, 0xED1C);
    func_L01_00516AA0(0x50007, 1, 1);
    func_L01_00516470(0x50008, 0.0f, 0.0f);
    func_L01_005170B8(0x50008, (D_L39_0049A010.a << 24) | (D_L39_0049A010.b << 16) | (D_L39_0049A010.g << 8) | D_L39_0049A010.r);
    func_L01_00517538(0x50008, 0.05f, 0.062000003f);
    func_L01_00517190(0x50008, 0xED1C);
    func_L01_00516AA0(0x50008, 1, 1);
    func_L39_005DC4C0(D_L39_00352940.f20C->f40, (s32 *)&x0, (s32 *)&y0);
    func_L01_00516470(0x50009, x0, y0);
    func_L01_00517538(0x50009, 0.05f, 0.062000003f);
    func_L01_00516AA0(0x50009, 1, 1);
    func_L01_00516AA0(0x50009, 0x40, 1);
    func_L01_00516728(0x50009, 0.002f, 0.002f);
    func_L01_00516C78(0x50009, 3, 3);
    func_L01_00517190(0x50009, 0xED33);
    func_L01_005168F0(0x50009, func_L39_005DD390(D_L39_00352940.f20C->f40));
    if (D_L39_00352940.f20C->f88 == 0) {
        func_L01_005170B8(0x50009, 0x60000000 | D_L39_00499FF0.r | (D_L39_00499FF0.g << 8) | (D_L39_00499FF0.b << 16));
    } else {
        func_L01_005170B8(0x50009, 0x60000000 | D_L39_00499FF8.r | (D_L39_00499FF8.g << 8) | (D_L39_00499FF8.b << 16));
    }
    func_L39_005DC4C0(D_L39_00352940.f20C->f44, (s32 *)&x1, (s32 *)&y1);
    func_L01_00516470(0x5000A, x1, y1);
    func_L01_00517538(0x5000A, 0.05f, 0.062000003f);
    func_L01_00516AA0(0x5000A, 1, 1);
    func_L01_00516AA0(0x5000A, 0x40, 1);
    func_L01_00516728(0x5000A, 0.002f, 0.002f);
    func_L01_00516C78(0x5000A, 3, 3);
    func_L01_00517190(0x5000A, 0xED33);
    func_L01_005168F0(0x5000A, func_L39_005DD390(D_L39_00352940.f20C->f44));
    func_L01_005170B8(0x5000A, 0x60000000 | D_L39_00499FF8.r | (D_L39_00499FF8.g << 8) | (D_L39_00499FF8.b << 16));
    if (D_L39_00352940.f20C->f8C == 0) {
        func_L01_005170B8(0x5000A, 0x60000000 | D_L39_00499FF0.r | (D_L39_00499FF0.g << 8) | (D_L39_00499FF0.b << 16));
    } else {
        func_L01_005170B8(0x5000A, 0x60000000 | D_L39_00499FF8.r | (D_L39_00499FF8.g << 8) | (D_L39_00499FF8.b << 16));
    }
    i = 0x5000B;
    do {
        if (func_L39_005DC4C0(D_L39_00352940.f20C->f60[i - 0x5000B], (s32 *)&x2, (s32 *)&y2) != 0) {
            func_L01_00516470(i, x2, y2);
            func_L01_00516AA0(i, 1, 1);
        } else {
            func_L01_00516AA0(i, 1, 0);
        }
        func_L01_00517538(i, 0.05f, 0.062000003f);
        func_L01_00516C78(i, 3, 3);
        func_L01_00516AA0(i, 0x40, 1);
        func_L01_00516728(i, 0.002f, 0.002f);
        func_L01_00517190(i, 0xED34);
        i++;
    } while (i <= 0x50012);
    i = 0x5001B;
    do {
        func_L01_00517538(i, 0.05f, 0.062000003f);
        func_L01_00516AA0(i, 1, 0);
        func_L01_00516AA0(i, 0x40, 1);
        func_L01_00516728(i, 0.002f, 0.002f);
        func_L01_00516C78(i, 3, 3);
        func_L01_00517190(i, 0xED36);
        i++;
    } while (i <= 0x50022);
    i = 0x50013;
    do {
        func_L01_00517538(i, 0.035f, 0.0434f);
        func_L01_00516AA0(i, 1, 0);
        func_L01_00516AA0(i, 0x40, 1);
        func_L01_00516728(i, 0.002f, 0.002f);
        func_L01_00516C78(i, 3, 3);
        func_L01_00517190(i, 0xED35);
        i++;
    } while (i <= 0x5001A);
    func_003E8630(0x50001, 0x50006);
    func_003E8630(0x50001, 0x50007);
    func_003E8630(0x50001, 0x50008);
    func_003E8630(0x50001, 0x50009);
    func_003E8630(0x50001, 0x5000A);
    for (i = 0x5000B; i <= 0x50012; i++) {
        func_003E8630(0x50002, i);
    }
    for (i = 0x5001B; i <= 0x50022; i++) {
        func_003E8630(0x50003, i);
    }
    for (i = 0x50013; i <= 0x5001A; i++) {
        func_003E8630(0x50004, i);
    }
    func_003E8630(0x50005, 0x50023);
    func_003E8630(0x50005, 0x50024);
    func_003E8630(0x50000, 0x50001);
    func_003E8630(0x50000, 0x50002);
    func_003E8630(0x50000, 0x50003);
    func_003E8630(0x50000, 0x50004);
    func_003E8630(0x50000, 0x50005);
    func_003E8348(0x17, 0x50000);
    func_003E6FF0(arg0, 1);
    func_L39_005DBF90(-1);
    func_L01_004D2110(0);
}
/* localdecomp:end func_L39_005DC648 */
