/* NTSC-U draft (Claude wave K): C of func_L39_005F91C8, the NTSC-U twin of func_L39_005FB960, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details) (NTSC-U twin "func_L39_005F91C8", whose code is not the PAL one).
 * Worker's note: best C near/func_L39_005F91C8.max.c: 106 position diffs / 29 aligned hunks (266 vs 272 insns); frame 0x70, all 9 callee-saved registers and spills (first/second at sp+0x18/0x1C) equal retail. Blocks: in mine the two index tails (counter arms and the status==0 ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_005FB960 (src/levels/shared/L39_005FB708.c) */

/* localdecomp:start func_L39_005F91C8 */
typedef struct {
    s32 counter;
    u8 pad4[0x5C];
    s32 active;
    u8 mode;
} Stream_5F91C8;
typedef struct {
    s32 sector;
    s32 size;
} File_5F91C8;
typedef struct {
    s32 f0;
    s32 base;
    File_5F91C8 files[1];
} Toc_5F91C8;
typedef struct {
    u8 pad0[0x34];
    s32 f34;
    u8 pad38[0x4C - 0x38];
    s32 f4C;
} Out_5F91C8;
typedef struct {
    u8 pad0[0xAD];
    u8 bAD;
} Mode_5F91C8;
typedef struct {
    u8 pad0[0x20];
    unsigned long q20;
} Q_5F91C8;

extern s32 D_L39_0024CBB0;
extern s32 D_L39_0024CBB4;
extern s32 *D_L39_0024CBB8;
extern s32 D_L39_0024CBBC;
extern s32 D_L39_0024CBC0;
extern s32 D_L39_0024CBD8_005F91C8;
extern s32 D_L39_00240470;
extern s32 D_L39_00240474;
extern s32 D_L39_002405E8_005F91C8;
extern u8 D_L39_00241264[];
extern s32 D_L39_0025F600[];
extern s32 D_L39_0025F780[];
extern Out_5F91C8 D_L39_0025CFC0;
extern Toc_5F91C8 D_L39_001F0B80;
extern s32 D_L39_001F0B8C[];
extern s32 D_001A4560[];
extern Mode_5F91C8 D_001A5990;
extern void func_0038E410(void *);
extern void func_L39_005BD880(s32, s32);
extern void func_003A3DA0(s32);
extern void func_L01_00478CA8(void);
extern void func_L39_005FA660(void);
extern void func_001264E0(s32);
extern void func_L39_005F1248(void);
extern void func_L39_005BFDC8(void);
extern void func_00194B28(s32);
extern void func_L39_005A43D8(void);
extern void func_00194A60(s32, s32, void *, void *);
extern void func_003A3288(s32, s32, s32, s32);
extern s32 func_003AA2E8(s32, s32, void *, s32, s32);
extern void func_L39_005F8EE8(void);
extern s32 func_003A3220(s32);
extern void func_0038E248(void *, s32 *, s32 *);
extern void func_0013A9D8(void *);
extern void func_001331A0(s32, s32);
extern void func_L39_005F3D60(void);
extern void func_003A3BB8_005F91C8(void);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern u8 D_00194F40[];
extern Q_5F91C8 D_L39_0025DEC0;

void func_L39_005F91C8(void)
{
    u8 buf[4];
    s32 frame;
    s32 status;
    s32 first;
    s32 second;
    u8 *destination;
    s32 result;
    s32 done;
    s32 index;
    s32 sel;
    s32 *desc;
    Stream_5F91C8 *stream;

    if (D_L39_0024CBB4 == 0) {
        func_0038E410(D_L39_0025F600);
        func_L39_005BD880(0, 0);
        return;
    }
    first = D_L39_0025F780[3];
    second = D_L39_0025F780[5];
    destination = (u8 *)(second + 0xF8000);
    func_003A3DA0(1);
    D_L39_00240470 = D_L39_00240474;
    func_L01_00478CA8();
    func_L39_005FA660();
    func_003A3DA0(1);
    func_001264E0(0);
    func_L39_005F1248();
    func_L39_005BFDC8();
    func_00194B28(0);
    while (D_001A4560[0x15C / 4] >= 3 || D_001A4560[0x164 / 4] >= 0) {
        func_L39_005A43D8();
    }
    frame = 0;
    status = -1;
    done = 0;
    for (;;) {
        desc = D_L39_0024CBB8;
        if (desc != 0 && desc[0] != 0) {
            buf[0] = 0x64;
            buf[1] = D_L39_00241264[0];
            buf[2] = 0;
            func_00194B28(0);
            func_00194A60(D_L39_0024CBB8[0] + D_L39_001F0B80.base, 0x10, destination, buf);
            func_00194B28(0);
            D_L39_0025CFC0.f4C = (s32)destination;
        } else {
            D_L39_0025CFC0.f4C = 0;
        }
        D_L39_0025CFC0.f34 = 0;
        func_003A3288(first, D_L39_0024CBD8_005F91C8 * 2, second, 0xF8000);
        result = func_003AA2E8(D_L39_0024CBB0, D_L39_0024CBB4, func_L39_005F8EE8, D_L39_0024CBBC, D_L39_0024CBC0);
        stream = (Stream_5F91C8 *)D_L39_0025F600;
        if ((result ^ 1) == 0) {
            stream->mode = 1;
        }
        if (result != 0 && (D_L39_002405E8_005F91C8 & 0x40) == 0) {
            stream->mode = 1;
            func_0038E410(stream);
        }
        if (D_L39_0025F600[0] != 0) {
            D_L39_0025F600[0]++;
            if (D_L39_0025F600[0] + D_001A5990.bAD >= 4) {
                D_L39_0025F600[0] = 1;
            }
            if (D_L39_0025F600[0] == 2) {
                D_L39_002405E8_005F91C8 = 0;
                if (D_001A5990.bAD != 0) {
                    D_L39_0024CBC0 = 0;
                    sel = 0x1D;
                } else {
                    D_L39_0024CBC0 = 1;
                    sel = 0x1F;
                }
            } else if (D_L39_0025F600[0] == 3) {
                D_L39_0024CBC0 = 1;
                sel = 0x1E;
                D_L39_002405E8_005F91C8 = 0;
            } else {
                D_L39_0024CBC0 = 0;
                sel = 0;
                D_L39_002405E8_005F91C8 = 1;
            }
            index = func_003A3220(sel);
            D_L39_0024CBB8 = (s32 *)&D_L39_001F0B80.files[index * 2];
            D_L39_0024CBB0 = D_L39_001F0B80.files[index * 2 + 1].sector + D_L39_001F0B80.base;
            D_L39_0024CBB4 = D_L39_001F0B80.files[index * 2 + 1].size;
        } else {
            stream = (Stream_5F91C8 *)D_L39_0025F600;
            if (stream->active == 0) {
                done = 1;
            } else {
            func_0038E248(stream, &frame, &status);
            if (status == 0) {
                D_L39_0024CBC0 = (frame == 0x1F);
                index = func_003A3220(frame);
                D_L39_0024CBB8 = (s32 *)&D_L39_001F0B80.files[index * 2];
                D_L39_0024CBB0 = D_L39_001F0B80.files[index * 2 + 1].sector + D_L39_001F0B80.base;
                D_L39_0024CBB4 = D_L39_001F0B80.files[index * 2 + 1].size;
            } else if (status == 1) {
                done = 1;
            }
            }
        }
        if (done) {
            break;
        }
    }
    func_00194B28(0);
    func_0013A9D8(D_00194F40);
    func_001331A0(0, 0);
    func_L39_005F3D60();
    D_L39_0025DEC0.q20 = 0;
    func_003A3BB8_005F91C8();
    if (result == 0 && status == 1) {
        func_L39_005BD7D8(2, 2, frame, 0, 0);
    } else {
        func_L39_005BD880(0, 0);
    }
}
/* localdecomp:end func_L39_005F91C8 */
