/* First draft (wave 13, r25) of level 39's boot init, modelled on its matched twins frontbin
 * func_00397FE8 (src/frontbin/397D48.c) and boot_elf func_003983C8 (src/boot_elf/text/398190.c).
 * This file (allowed forms only: the image header at 0x01000000 is an extern, D_01000000) is
 * 363 diff at level 39: the extern costs the ddiu after lui s0, 0x100, which shifts the rest and
 * moves the image pointer out of s0 (the segment copies then use it as their base).
 * The same C with the twins' own form, image = (Img_0059DEB8 *)0x01000000; (a hardcoded address,
 * which this wave's rules do not allow), gives ALL_PLACES_MATCH 15; TYPE_CONTRACT_PASS and an object
 * audit "ok": true (build/codex/wr25/func_L39_0059DEB8.const.c and its .checks/receipt.json).
 * Other findings: func_0013AB78 returns int (the first flag test's lbu goes to v1 only then), the
 * level globals need .extern X, 16 (absolute lui/at access), the struct copies are u16 arrays of
 * 15/16/17 elements (lh tail), the jump table maps 2->2, 3->4, 4->3, 5->5, 1/default->0.
 */#include "common.h"

/* localdecomp:start func_L39_0059DEB8 */
typedef struct { s32 state; u8 pad4[0xA9]; u8 mode; u8 padAE[9]; u8 language; } State_0059DEB8;
typedef struct { u8 pad0[0x64C]; s32 base; u8 pad650[8]; s32 offset; s32 sectors; } Disc_0059DEB8;
typedef struct { u8 pad[0x24]; s32 a, b, c, d, e, f, g, h; } Sizes_0059DEB8;
typedef struct { u8 pad[0x18]; s32 a; u8 pad1C[0x14]; s32 b; } Cache_0059DEB8;
typedef struct { s32 a; s32 b; } Seg_0059DEB8;
typedef struct { u8 pad[0x40]; s32 off; s32 size; Seg_0059DEB8 seg[13]; } Img_0059DEB8;
typedef struct { u16 c[15]; } N30_0059DEB8;
typedef struct { u16 c[16]; } N32_0059DEB8;
typedef struct { u16 c[17]; } N34_0059DEB8;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    u8 pad20[0x5E - 0x20];
    u8 name5E[0x17C - 0x5E];
    s32 f17C;
    u8 b180;
    u8 pad181[0x1A2 - 0x181];
    N30_0059DEB8 n1A2;
    u8 pad1C0[0x202 - 0x1C0];
    N32_0059DEB8 n202;
    u8 pad222[0x262 - 0x222];
    N34_0059DEB8 n262;
    u8 pad284[0x2C4 - 0x284];
    s32 f2C4;
    u8 b2C8;
} Prof_0059DEB8;

extern State_0059DEB8 D_001A5810_0059DEB8;
extern u8 D_L39_0024139D;
__asm__(".extern D_L39_0024139D, 16");
extern s32 D_L39_002413A0;
__asm__(".extern D_L39_002413A0, 16");
extern u8 D_L39_00242B98[];
extern Disc_0059DEB8 D_001F0A00_0059DEB8;
extern u8 D_0010F1A0[];
extern u8 D_01F2BEF8[];
extern u8 D_01F38000[];
extern Img_0059DEB8 D_01000000;
extern Prof_0059DEB8 D_001A5CD0_0059DEB8;
extern N30_0059DEB8 D_L39_00242BB0;
extern N32_0059DEB8 D_L39_00242BD0;
extern N34_0059DEB8 D_L39_00242BF0;
extern Sizes_0059DEB8 D_001FC450_0059DEB8;
extern Cache_0059DEB8 D_001FC340_0059DEB8;
extern s32 D_L39_002402A0;
__asm__(".extern D_L39_002402A0, 16");
extern s32 D_L39_002402A4;
__asm__(".extern D_L39_002402A4, 16");
extern s32 D_L39_002402D0;
__asm__(".extern D_L39_002402D0, 16");
extern s32 D_L39_002402E0;
__asm__(".extern D_L39_002402E0, 16");
extern u8 D_L39_0025F7C0[];
extern u8 D_L39_0025F500[];

void func_L39_0059DEB8(void) {
    extern void func_00133100(void);
    extern s32 func_0013AB78(s32);
    extern void func_L39_00596EE0(void);
    extern void func_003A0258(void);
    extern void func_L39_00587A30(s32);
    extern void func_00194E50();
    extern void func_0013A9D8(void *);
    extern void func_L39_005FCC58(void);
    extern void func_003A9108(void);
    extern void func_L39_005FD668(void);
    extern void func_L39_00587E80(void);
    extern void func_00138748(s32);
    extern void func_00138C48(s32);
    extern s32 func_0012C740(void *);
    extern s32 func_0012C6F0(void);
    extern void func_00129490(s32);
    extern void func_0012CD60(void);
    extern void func_0012B8B8(void);
    extern void func_0012CDB0(void);
    extern s32 func_0012BD48(void);
    extern s32 func_0012AA00(void);
    extern s32 func_00194ED8(s32, s32, void *);
    extern void func_001264E0(s32);
    extern void func_L39_005A6020(void *);
    extern void func_003A8F90(u32);
    extern void func_00194F28(void *);
    extern void func_003A0760(u8 *, u32);
    extern s32 func_0012B9B0(s32, s32, s32);
    extern void func_00195010(void);
    extern s32 func_00381FF0(s32);
    extern void func_001206F4(void *, s32);
    extern void func_L39_005F40B8(void);
    extern void func_L39_005C32A0(void);
    extern void func_L39_005A8658(void);
    extern void func_00387268(void);
    extern void func_L39_005872D8(void);
    extern void func_L39_005F1560(void);
    extern void func_003A12D0(void);
    extern void func_L01_003EE638(void);
    extern s32 func_00191F40(void);
    extern s32 func_00191FA8(void);
    extern void func_0038CB78(void *, s32, s32);
    extern void func_00139EA0(void *, s16, s16, s16, s16, s16, s16, s16);
    extern void func_0013A1C8(void *, u8 *);
    extern s32 func_001331A0(s32, s32);
    extern void func_L39_005782F0(void);
    extern s32 func_00398470(s32);
    extern void func_L39_0059A280(void *);
    u32 work[512];
    u32 sentinel;
    Img_0059DEB8 *image;
    Img_0059DEB8 *copy;
    Prof_0059DEB8 *p;
    u8 *heap;
    s32 result;

    func_00133100();
    func_0013AB78(1);
    if (!D_L39_0024139D) {
        D_L39_002413A0 = 0;
        D_001A5810_0059DEB8.mode = 0;
    }
    func_L39_00596EE0();
    func_003A0258();
    func_L39_00587A30(1);
    func_0013A9D8(func_00194E50);
    func_L39_005FCC58();
    func_L39_0059DDB0();
    func_L39_005FCC58();
    func_003A9108();
    func_L39_005FD668();
    func_L39_00587E80();
    func_00138748(0);
    func_00138C48(0);
    while (!func_0012C740(D_L39_00242B98)) {}
    while (!func_0012C6F0()) {}
    func_00129490(0);
    func_0012CD60();
    func_0012B8B8();
    func_0012CDB0();
    func_0012BD48();
    func_00138748(0);
    func_00138C48(0);
    func_L39_0059DE98();
    func_0012AA00();
    func_00194ED8(1000, 1, &work);
    func_001264E0(0);
    D_001A5810_0059DEB8.state = 1;
    func_L39_005A6020(&work);
    func_003A8F90((u32)D_0010F1A0);
    func_00194F28(D_01F2BEF8);
    heap = D_01F38000 - (D_001F0A00_0059DEB8.sectors << 11);
    func_00194ED8(D_001F0A00_0059DEB8.offset + D_001F0A00_0059DEB8.base, D_001F0A00_0059DEB8.sectors, heap);
    func_001264E0(0);
    image = &D_01000000;
    func_003A0760(heap, (u32)image);
    result = func_0012B9B0(0, 0x4E900, 0);
    sentinel = 0x132400;
    func_L39_0059DD00(image->off + (s32)image, image->size, result, 0x51, (s32)&sentinel - 1);
    func_L39_0059DCD8();
    p = &D_001A5CD0_0059DEB8;
    p->f18 = 0;
    p->f1C = 1;
    p->name5E[0] = 0;
    p->f17C = 0;
    p->n1A2 = D_L39_00242BB0;
    p->n202 = D_L39_00242BD0;
    p->n262 = D_L39_00242BF0;
    p->f2C4 = 0x275B;
    p->f1C = p->f1C % 22;
    p->f18 = p->f18 % 2;
    p->b2C8 = 1;
    p->b180 = 1;
    if (p->name5E[0] == 0) {
        func_001206F4(p->name5E, func_00381FF0(0x14BE));
    }
    func_L39_0059DCD8();
    func_00195010();
    copy = (Img_0059DEB8 *)D_01F38000;
    copy->seg[0] = image->seg[0];
    copy->seg[0].a -= (s32)copy - (s32)heap;
    copy->seg[1] = image->seg[1];
    copy->seg[1].a -= (s32)copy - (s32)heap;
    copy->seg[2] = image->seg[2];
    copy->seg[2].a -= (s32)copy - (s32)heap;
    copy->seg[3] = image->seg[3];
    copy->seg[3].a -= (s32)copy - (s32)heap;
    copy->seg[4] = image->seg[4];
    copy->seg[4].a -= (s32)copy - (s32)heap;
    copy->seg[5] = image->seg[5];
    copy->seg[5].a -= (s32)copy - (s32)heap;
    copy->seg[6] = image->seg[6];
    copy->seg[6].a -= (s32)copy - (s32)heap;
    copy->seg[7] = image->seg[7];
    copy->seg[7].a -= (s32)copy - (s32)heap;
    copy->seg[8] = image->seg[8];
    copy->seg[8].a -= (s32)copy - (s32)heap;
    copy->seg[9] = image->seg[9];
    copy->seg[9].a -= (s32)copy - (s32)heap;
    copy->seg[10] = image->seg[10];
    copy->seg[10].a -= (s32)copy - (s32)heap;
    copy->seg[11] = image->seg[11];
    copy->seg[11].a -= (s32)copy - (s32)heap;
    copy->seg[12] = image->seg[12];
    copy->seg[12].a -= (s32)copy - (s32)heap;
    func_L39_005F40B8();
    func_00138C48(0);
    func_L39_005C32A0();
    D_001FC450_0059DEB8.a = 0;
    D_001FC450_0059DEB8.b = 0x60000;
    D_001FC450_0059DEB8.c = 0x70000;
    D_001FC450_0059DEB8.d = 0xB0000;
    D_001FC450_0059DEB8.e = 0xF0000;
    D_001FC450_0059DEB8.f = 0x160000;
    D_001FC450_0059DEB8.g = 0x1D0000;
    D_001FC450_0059DEB8.h = 0x1E0000;
    D_L39_002402A4 = 0;
    D_L39_002402A0 = -1;
    D_L39_002402D0 = -1;
    D_L39_002402E0 = -1;
    D_001FC340_0059DEB8.b = -1;
    D_001FC340_0059DEB8.a = -1;
    func_00138C48(0);
    func_L39_005A8658();
    func_00387268();
    func_L39_005872D8();
    func_003A9108();
    func_L39_0059DCD8();
    func_00138C48(0);
    func_L39_005F1560();
    func_L39_0059DCD8();
    func_003A12D0();
    func_L39_0059DCD8();
    func_L01_003EE638();
    if (!D_L39_0024139D) {
        switch (func_00191F40()) {
        case 2: D_001A5810_0059DEB8.language = 2; break;
        case 3: D_001A5810_0059DEB8.language = 4; break;
        case 4: D_001A5810_0059DEB8.language = 3; break;
        case 5: D_001A5810_0059DEB8.language = 5; break;
        case 1: default: D_001A5810_0059DEB8.language = 0; break;
        }
    }
    if (!D_L39_0024139D) {
        switch (func_00191FA8()) {
        case 1: D_001A5810_0059DEB8.mode = 1; break;
        case 0: case 2: D_001A5810_0059DEB8.mode = 0; break;
        }
    }
    func_0038CB78(D_L39_0025F7C0, 0x80808080, 0x100);
    func_00139EA0(&work, 0x3FFB, 1, 0, 0, 0, 8, 8);
    func_001264E0(0);
    func_0013A1C8(&work, D_L39_0025F7C0);
    func_001331A0(0, 0);
    func_L39_005782F0();
    func_00398470(0);
    *(volatile u32 *)0x10000810 = 0x82;
    *(volatile u32 *)0x10000800 = 0;
    func_L39_0059A280(D_L39_0025F500);
    func_L39_0059DCD8();
}
/* localdecomp:end func_L39_0059DEB8 */
