/* func_L39_005A61D8: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 9340 bytes (2335 instr), places: 15 levels (39, 40, 42, 44, 46, 48, ...), file: src/levels/shared/L39_005A61D8.c,
   flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function, the memory-card state machine (one prologue, one epilogue); switch(D_1A43E0.state) with 0x25 cases
     (jtbl_00479EB0, 36 entries) and a nested switch on sub-state in the save/load cases (jtbl_00479F40).
   rac2 twin: func_00298F00 (rac2-decomp src/game/00298F00.c, matched), opcode similarity 0.861; rac3 frontbin
     func_0039C410 is a 0.951 sibling (same machine, unmatched in rac3; held by the cross-game agent). The earlier
     API job (~/RACSwarm/rac3-api/jobs/func_L39_005A61D8*/func.c, out of budget) already wrote the whole machine; this
     file is that draft plus my fix of one tail-order point.
   Mapping: McState (D_1A43E0, rac2 D_001393E0): card[2] x 0xA0, cmd +0x140, result +0x144, cur +0x14C, busy +0x154,
     fd +0x158, state +0x15C, sub +0x160, next_state/next_card +0x164/+0x168, err/err_card +0x16C/+0x170, buf +0x174,
     size +0x178, probe +0x180, retry +0x184, +0x188 counter. Callees: func_13B838 = mcSync, 13B958 = mcGetInfo, 13BC30/13BE30/
     13BAD8/13B1F8/13B5A8/13B358/13B320/13BD00/13B6C0/13B418 = open/format/read/write/close family (same prototypes as rac2's
     func_00127B88.. family, renamed +0x14... see the draft's externs).
   Identical / changed / added / removed: all 36 state cases and the nested switch exist in both; vs rac2 the error codes
     (0x2710-0x2716, 0x1B, 0x1C), the sub-state counts and the string constants (D_2411F8.. D_2412DC) changed; rac2 case
     structure otherwise carried.
   Draft: compiles; level 39: 2347 instr vs 2335 retail (+12 instr), equal opcodes 2310 of 2335 (98.9%); `chk.sh` prints
     1957 diff only because the +12 shifts every later branch/address. 26 hunks of 1-10 instr (listed below).
   Remaining hunks (retail offsets in the function), these are the whole job:
     1. 0x5C8: case 10 branch (status=-2): retail jumps (b 0x1bf4) into the shared tail {busy=0;state=0;cur=0} at the end
        of a LATER case; mine emits an own copy. Same family at 0x10F4, 0x1298, 0x188C, 0x1C44 (tail merged vs copied:
        gcc's cross-jumping needs the same insn order/regs; try making the branch the last statement, or `goto`-free
        restructure so the first copy follows in the code layout).
     2. 0xB64/0xBA8/0xC10: scheduling of `&sp+0x54` out-arg address and of size/buf stores (buf, size=0x178, counter 0x188++
        loaded before the call result use): reorder the statements so `size = ...; D_1A43E0.x188++` precede the call.
     3. 0xD00/0xD0C: loop-exit inversion (retail `bltz` forward + shared block, mine `bgez` back): while vs do-while around
        the fd close `func_13B358(D_1A43E0.fd)` block; same at 0x1880, 0x1C38.
     4. 0x1758/0x1760: `sw err_card` hoisted above `addiu 0x25` in case 0x25 (store order err/err_card).
     5. 0x17C0: retail has `.word 0x00a22818` (mult $ac3? raw word by fix_quadword_ops) where mine emits `mult $ac2`: a
        different accumulator; arises from two multiplies by 0xA0 (card index) close together; use the same expression
        shape (cur*0xA0 vs probe*0xA0) as the neighbouring cases.
   Left for Opus: do hunks 1-5 in that order (1 fixes the +12 instr, then 2-5 are local); run chkall at the end (15
     places share the file; NTSC-U carried).
*/
typedef struct {
    s32 x0;
    s32 pad[6];
} McSave_005A61D8;

typedef struct {
    s32 port;
    s32 slot;
    s32 type;
    s32 free;
    s32 result;
    s32 format;
    s16 status;
    s16 tries;
    s32 x1C;
    s32 used_blocks;
    s32 x24;
    s32 x28;
    s32 x2C;
    McSave_005A61D8 save[4];
} McCard_005A61D8;

typedef struct {
    McCard_005A61D8 card[2];
    s32 cmd;
    s32 result;
    s32 x148;
    s32 cur;
    s32 index;
    s32 busy;
    s32 fd;
    s32 state;
    s32 sub;
    s32 next_state;
    s32 next_card;
    s32 err;
    s32 err_card;
    u8 *buf;
    s32 size;
    s32 x17C;
    s32 probe;
    s32 retry;
    s32 x188;
} McState_005A61D8;

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
} McChunk_005A61D8;

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 size;
    s32 pad[3];
    char name[0x20];
} McDirEntry_005A61D8;

typedef struct {
    u8 pad0[0x64C];
    s32 x64C;
    s32 pad1[3];
    s32 x660;
    s32 x664;
} McCfg_005A61D8;

typedef struct {
    s32 pad[18];
    s32 flags;
} McFlags_005A61D8;

extern McState_005A61D8 D_1A43E0;
extern McCfg_005A61D8 D_1F0A00;
extern McFlags_005A61D8 D_1A4610;
extern McDirEntry_005A61D8 D_L39_00268C40[];
extern char D_L39_00268C60[];
extern char D_241210[];
extern char D_2411F8[];
extern char D_24123D[];
extern char D_24125D[];
extern char D_24127D[];
extern char D_2412AD[];
extern char D_241228[];
extern char D_241248[];
extern char D_241268[];
extern char D_241298[];
extern char D_2412B8[];
extern u8 D_2412DC[];
extern char D_L39_002430F8[];
extern char D_L39_00243100[];
extern char D_L39_00243108[];
extern char D_L39_00243110[];
extern char D_L39_00243130[];
extern char D_L39_00243150[];
extern char D_L39_00243170[];
extern char D_L39_00243190[];
extern char D_L39_002431B0[];
extern char D_L39_002431D0[];
extern u8 D_L39_00499348[];
extern u8 D_L39_004995D8[];
extern u8 D_21E260[];
extern s32 D_21E268[];
extern u8 D_224260[];
extern s32 D_L39_001D79B8;

extern s32 func_13B838(s32, void *, void *);
extern s32 func_13B958(s32, s32, void *, void *, void *);
extern s32 func_13BC30(s32, s32);
extern s32 func_13BE30(s32, s32);
extern s32 func_13BAD8(s32, s32, char *, s32, s32, void *);
extern void func_11D534(void *, s32, s32);
extern s32 func_1205B0(char *, char *);
extern s32 func_120B70(char *, char *, s32);
extern s32 func_120048(char *, char *, ...);
extern s32 func_1206F4(char *, char *);
extern s32 func_13B1F8(s32, s32, char *, s32);
extern s32 func_13B5A8(s32, void *, s32);
extern s32 func_13B358(s32);
extern s32 func_13B320(s32, s32, char *);
extern s32 func_13BD00(s32, s32, char *);
extern s32 func_13B6C0(s32, void *, s32);
extern s32 func_13B418(s32, s32, s32);
extern s32 func_0039E6A8(void *);
extern s32 func_0039E788(void *);
extern s32 func_0039E7C8(void *, s32, void *);
extern void func_L39_0059A218(s32, void *);
extern void func_L39_005C29A0(void *, s32, s32);
extern void func_L39_005A88B0(void *, s32, s32);
extern s32 func_L39_005A8968(void *, void *, s32, void *);
extern void func_L39_005A8CC8(void);

void func_L39_005A61D8(void)
{
    union {
        char name[0x40];
        struct {
            s32 seen[4];
            char name[0x40];
        } directory;
    } workspace;
    McState_005A61D8 *finished_card;

    if (D_1A43E0.busy) {
        D_1A43E0.busy = func_13B838(1, &D_1A43E0.cmd, &D_1A43E0.result) == 0;
        return;
    }
    D_1A43E0.busy = 1;

    switch (D_1A43E0.state) {
    case 0:
        if ((u32)D_1A43E0.probe >= 2)
            D_1A43E0.probe = 0;
        if (func_13B958(D_1A43E0.card[D_1A43E0.probe].port, D_1A43E0.card[D_1A43E0.probe].slot,
                        &D_1A43E0.card[D_1A43E0.probe].type, &D_1A43E0.card[D_1A43E0.probe].free,
                        &D_1A43E0.card[D_1A43E0.probe].format) == 0)
            D_1A43E0.state = 1;
        break;

    case 1:
        if (D_1A43E0.result != 0) {
            D_1A43E0.card[D_1A43E0.probe].status = -4;
            D_1A43E0.card[D_1A43E0.probe].result = D_1A43E0.result;
            D_1A43E0.card[D_1A43E0.probe].x24 = -1;
            D_1A43E0.card[D_1A43E0.probe].used_blocks = 0;
            D_1A43E0.card[D_1A43E0.probe].save[0].x0 = -1;
            D_1A43E0.card[D_1A43E0.probe].save[1].x0 = -1;
            D_1A43E0.card[D_1A43E0.probe].save[2].x0 = -1;
            D_1A43E0.card[D_1A43E0.probe].save[3].x0 = -1;
            D_1A43E0.card[D_1A43E0.probe].x1C = 0;
        }
        if (D_1A43E0.next_card < ++D_1A43E0.probe && D_1A43E0.next_state >= 0) {
            D_1A43E0.state = 2;
            if (D_1A43E0.next_card >= 0) {
                if (D_1A43E0.card[D_1A43E0.next_card].result == 0 || D_1A43E0.next_state == 0x18) {
                    D_1A43E0.cur = D_1A43E0.next_card;
                    D_1A43E0.state = D_1A43E0.next_state;
                    D_1A43E0.err = 0;
                } else {
                    D_1A43E0.err = 0x271A;
                }
            } else {
                D_1A43E0.err = 0x271A;
            }
            D_1A43E0.next_state = -1;
            D_1A43E0.next_card = -1;
            break;
        }
        if (D_1A43E0.probe < 2)
            D_1A43E0.state = 0;
        else
            D_1A43E0.state = 2;
        D_1A43E0.busy = 0;
        break;

    case 2:
        D_1A43E0.retry++;
        if (D_1A43E0.next_state >= 0 || D_1A43E0.retry >= 11) {
            D_1A43E0.retry = 0;
            D_1A43E0.probe = 0;
            D_1A43E0.state = 0;
        }
        D_1A43E0.busy = 0;
        break;

    case 3:
        if (D_1A43E0.card[D_1A43E0.cur].format == 0) {
            if (func_13BC30(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot) == 0) {
                D_1A43E0.state = 4;
            }
            break;
        }
        D_1A43E0.busy = 0;
        D_1A43E0.state = 2;
        break;

    case 4:
        if (D_1A43E0.result != 0) {
            D_1A43E0.err = 1;
            D_1A43E0.err_card = D_1A43E0.cur;
        }
        D_1A43E0.busy = 0;
        D_1A43E0.state = 0;
        D_1A43E0.cur = 0;
        break;

    case 5:
        if (D_1A43E0.card[D_1A43E0.cur].format == 0) {
            if (func_13BE30(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot) == 0) {
                D_1A43E0.state = 6;
            }
            break;
        }
        D_1A43E0.busy = 0;
        D_1A43E0.state = 2;
        break;

    case 6:
        if (D_1A43E0.result != 0) {
            D_1A43E0.err = 2;
            D_1A43E0.err_card = D_1A43E0.cur;
        }
        D_1A43E0.busy = 0;
        D_1A43E0.state = 0;
        D_1A43E0.cur = 0;
        break;

    case 7:
        if (func_13BAD8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot,
                        D_241210, 0, 11, D_L39_00268C40) == 0) {
            D_1A43E0.sub = 0;
            D_1A43E0.state = 8;
        }
        break;

    case 8:
        switch (D_1A43E0.sub) {
        case 0:
            if (D_1A43E0.result > 0) {
                s32 icon0;
                s32 icon1;
                s32 icon2;
                s32 icon3;
                s32 i;
                s32 blocks;
                icon0 = 0;
                func_11D534(workspace.directory.seen, 0, 16);
                icon1 = 0;
                icon2 = 0;
                icon3 = 0;
                blocks = 0;
                for (i = 0; i < D_1A43E0.result; i++) {
                    McDirEntry_005A61D8 *entry = &D_L39_00268C40[i];
                    char *filename = (char *)((s32)D_L39_00268C40 + i * 64 + 32);
                    s32 slot;
                    blocks += (entry->size + 1023U) >> 10;
                    if (func_1205B0(filename, D_24123D) == 0) icon0 = 1;
                    if (func_1205B0(filename, D_24125D) == 0) icon1 = 1;
                    if (func_1205B0(filename, D_24127D) == 0) icon2 = 1;
                    if (func_1205B0(filename, D_2412AD) == 0) icon3 = 1;
                    if (func_120B70(filename, D_L39_002430F8, 4) == 0 &&
                        func_120B70(filename + 5, D_L39_00243100, 4) == 0) {
                        slot = (u8)entry->name[4] - '0';
                        if (slot < 0) continue;
                        if (slot < 4) workspace.directory.seen[slot] = 1;
                    }
                }
                blocks += 1 + (D_1A43E0.result + 1) / 2;
                if ((u32)(blocks - 0x257) < 2 && D_1A43E0.result == 10 && icon0 && icon1 && icon2 && icon3 &&
                    workspace.directory.seen[0] && workspace.directory.seen[1] && workspace.directory.seen[2] &&
                    workspace.directory.seen[3]) {
                    D_1A43E0.card[D_1A43E0.cur].used_blocks = 0;
                    D_1A43E0.card[D_1A43E0.cur].status = -1;
                    D_1A43E0.sub = 1;
                    D_1A43E0.busy = 0;
                } else {
                    D_1A43E0.card[D_1A43E0.cur].used_blocks = blocks;
                    D_1A43E0.card[D_1A43E0.cur].status = -2;
                    D_1A43E0.state = 0;
                    D_1A43E0.cur = 0;
                    D_1A43E0.busy = 0;
                }
            } else {
                D_1A43E0.card[D_1A43E0.cur].status = -2;
                if (D_1A43E0.result == -2) {
                    D_1A43E0.err = 3;
                    D_1A43E0.err_card = D_1A43E0.cur;
                } else if (D_1A43E0.result >= 0) {
                    D_1A43E0.card[D_1A43E0.cur].status = -2;
                } else if (D_1A43E0.result != -4) {
                    D_1A43E0.err = 4;
                    D_1A43E0.err_card = D_1A43E0.cur;
                }
                D_1A43E0.state = 0;
                D_1A43E0.cur = 0;
                D_1A43E0.busy = 0;
            }
            break;
        case 1:
            func_120048(workspace.directory.name, D_2412B8, 0);
            if (func_13B1F8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, workspace.directory.name, 1) == 0) {
                D_1A43E0.sub++;
            }
            break;
        case 2:
            if (D_1A43E0.result >= 0) {
                D_1A43E0.fd = D_1A43E0.result;
                D_1A43E0.sub = 3;
            } else {
                D_1A43E0.card[D_1A43E0.cur].status = -2;
                D_1A43E0.err_card = D_1A43E0.cur;
                if (D_1A43E0.result == -7) {
                    D_1A43E0.err = 0x2710;
                } else if (D_1A43E0.result == -5) {
                    D_1A43E0.err = 0x2711;
                } else if (D_1A43E0.result == -4) {
                    D_1A43E0.err = 0x2712;
                } else if (D_1A43E0.result == -3) {
                    D_1A43E0.err = 0x2713;
                } else if (D_1A43E0.result == -2) {
                    D_1A43E0.err = 3;
                } else {
                    D_1A43E0.err = 4;
                }
                D_1A43E0.state = 0;
                D_1A43E0.cur = 0;
            }
            D_1A43E0.busy = 0;
            break;
        case 3:
            D_1A43E0.size = 8;
            if (func_13B5A8(D_1A43E0.fd, &D_1A43E0.card[D_1A43E0.cur].x28, 8) == 0) {
                D_1A43E0.sub = 4;
            }
            break;
        case 4:
            if (D_1A43E0.result == D_1A43E0.size) {
                D_1A43E0.card[D_1A43E0.cur].x24 = 0;
                if (D_1A43E0.card[D_1A43E0.cur].x28 != func_0039E6A8(D_L39_00499348)) {
                    D_1A43E0.card[D_1A43E0.cur].x24++;
                }
                if (D_1A43E0.card[D_1A43E0.cur].x2C != func_0039E6A8(D_L39_004995D8)) {
                    D_1A43E0.card[D_1A43E0.cur].x24++;
                }
                D_1A43E0.busy = 0;
                D_1A43E0.sub = 5;
            } else {
                D_1A43E0.card[D_1A43E0.cur].status = -2;
                D_1A43E0.err_card = D_1A43E0.cur;
                if (D_1A43E0.result >= 0) {
                    D_1A43E0.err = 0x2716;
                    if (func_13B358(D_1A43E0.fd) == 0) {
                        D_1A43E0.state = 0;
                        D_1A43E0.cur = 0;
                        D_1A43E0.busy = 0;
                    }
                    break;
                }
                if (D_1A43E0.result == -5) {
                    D_1A43E0.err = 0x2711;
                } else if (D_1A43E0.result == -4) {
                    D_1A43E0.err = 0x2714;
                } else if (D_1A43E0.result == -3) {
                    D_1A43E0.err = 0x2715;
                } else if (D_1A43E0.result == -2) {
                    D_1A43E0.err = 3;
                } else {
                    D_1A43E0.err = 4;
                }
                D_1A43E0.state = 0;
                D_1A43E0.cur = 0;
                D_1A43E0.busy = 0;
            }
            break;
        case 5:
            if (func_13B358(D_1A43E0.fd) == 0) {
                D_1A43E0.busy = 0;
                D_1A43E0.state = 21;
            }
            break;
        }
        break;

    case 9:
        D_1A43E0.state = 10;
        D_1A43E0.sub = 0;
        D_1A43E0.x188 = 6;
        D_1A43E0.card[D_1A43E0.cur].status = 0;
    case 10:
        switch (D_1A43E0.sub) {
        case 0:
            if (D_1A43E0.card[D_1A43E0.cur].free + D_1A43E0.card[D_1A43E0.cur].used_blocks >= 0x258) {
                D_1A43E0.sub = 1;
            } else {
                D_1A43E0.err = 7;
                D_1A43E0.err_card = D_1A43E0.cur;
                D_1A43E0.state = 0;
                D_1A43E0.cur = 0;
            }
            D_1A43E0.busy = 0;
            break;
        case 1:
            if (func_13B320(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, D_2411F8) == 0) {
                D_1A43E0.sub = 2;
            }
            break;
        case 2:
            if (D_1A43E0.result == 0 || D_1A43E0.result == -4) {
                D_1A43E0.sub = 3;
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result == -3) {
                D_1A43E0.err = 7;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 6;
            } else {
                D_1A43E0.err = 0xD;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 3: {
            McChunk_005A61D8 *chunk;

            func_L39_0059A218(D_1F0A00.x664 << 11, &chunk);
            func_L39_005C29A0(chunk, D_1F0A00.x660 + D_1F0A00.x64C, D_1F0A00.x664);
            D_1A43E0.sub = 4;
            D_1A43E0.busy = 0;
            break;
        }
        case 4:
            if (*(s16 *)0x225664 == 0) {
                D_1A43E0.sub = 5;
            }
            D_1A43E0.busy = 0;
            break;
        case 5:
        case 9:
        case 13:
        case 17:
        case 22:
            switch (D_1A43E0.sub) {
            case 5:
                func_1206F4(workspace.name, D_241228);
                break;
            case 9:
                func_1206F4(workspace.name, D_241248);
                break;
            case 13:
                func_1206F4(workspace.name, D_241268);
                break;
            case 22:
                func_1206F4(workspace.name, D_241298);
                break;
            case 17:
                func_120048(workspace.name, D_2412B8, D_1A43E0.card[D_1A43E0.cur].status);
                break;
            }
            if (func_13B1F8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, workspace.name, 0x203) == 0) {
                D_1A43E0.fd = -1;
                D_1A43E0.sub++;
            }
            break;
        case 6:
        case 10:
        case 14:
        case 18:
        case 23: {
            McChunk_005A61D8 *chunk;

            if (D_1A43E0.result >= 0) {
                if (D_1A43E0.fd < 0) {
                    D_1A43E0.fd = D_1A43E0.result;
                }
                func_L39_0059A218(*(s32 *)0x1F1064 << 11, &chunk);
                switch (D_1A43E0.sub) {
                case 6:
                    D_1A43E0.size = 0x3C4;
                    D_1A43E0.x188++;
                    D_1A43E0.buf = (u8 *)chunk + chunk->x0;
                    break;
                case 10:
                    D_1A43E0.size = chunk->xC;
                    D_1A43E0.buf = (u8 *)chunk + chunk->x8;
                    D_1A43E0.x188 += (D_1A43E0.size + 0x3FF) >> 10;
                    break;
                case 23:
                    D_1A43E0.buf = D_2412DC;
                    D_1A43E0.size = (0x258 - D_1A43E0.x188) << 10;
                    break;
                case 14: {
                    s32 n = func_0039E7C8(D_21E260, 0, &D_L39_001D79B8);
                    D_1A43E0.buf = D_21E260;
                    D_1A43E0.size = n;
                    D_1A43E0.x188 += (n + 0x3FF) >> 10;
                    break;
                }
                case 18: {
                    s32 n = func_0039E6A8(D_L39_00499348);
                    D_1A43E0.size = n + func_0039E6A8(D_L39_004995D8) * 0x25 + 8;
                    D_1A43E0.buf = (u8 *)chunk + chunk->x10;
                    D_1A43E0.x188 += (D_1A43E0.size + 0x3FF) >> 10;
                    break;
                }
                }
                if (func_13B6C0(D_1A43E0.fd, D_1A43E0.buf, D_1A43E0.size) == 0) {
                    D_1A43E0.sub++;
                }
            } else {
                D_1A43E0.err = 0xA;
                D_1A43E0.err_card = D_1A43E0.cur;
                D_1A43E0.state = 0;
                D_1A43E0.cur = 0;
                D_1A43E0.busy = 0;
            }
            break;
        }
        case 7:
        case 11:
        case 15:
        case 19:
        case 24:
            if (D_1A43E0.result == D_1A43E0.size) {
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.sub++;
                }
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result >= 0) {
                finished_card = &D_1A43E0;
                finished_card->err = 0xB;
                if (func_13B358(finished_card->fd) == 0) {
                    finished_card->busy = 0;
                    goto reset_state;
                }
                break;
            }
            if (D_1A43E0.result == -4) {
                D_1A43E0.err = 8;
            } else if (D_1A43E0.result == -3) {
                D_1A43E0.err = 7;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 6;
            } else {
                D_1A43E0.err = 0xD;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 8:
        case 12:
        case 16:
        case 20:
            if (D_1A43E0.result == 0) {
                D_1A43E0.sub++;
            } else {
                D_1A43E0.err = 0xC;
                D_1A43E0.err_card = D_1A43E0.cur;
                D_1A43E0.state = 0;
                D_1A43E0.cur = 0;
            }
            D_1A43E0.busy = 0;
            break;
        case 21:
            if (++D_1A43E0.card[D_1A43E0.cur].status < 4) {
                D_1A43E0.sub = 17;
            } else {
                D_1A43E0.sub++;
            }
            D_1A43E0.busy = 0;
            break;
        case 25:
            D_1A43E0.card[D_1A43E0.cur].x28 = func_0039E6A8(D_L39_00499348);
            D_1A43E0.card[D_1A43E0.cur].x2C = func_0039E6A8(D_L39_004995D8);
            D_1A43E0.card[D_1A43E0.cur].status = -1;
            D_1A43E0.card[D_1A43E0.cur].x24 = 0;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            break;
        }
        break;

    case 11:
        D_1A43E0.state = 12;
        D_1A43E0.sub = 0;
        D_1A43E0.card[D_1A43E0.cur].status = -2;
    case 12:
        switch (D_1A43E0.sub) {
        case 0:
            if (func_13BAD8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, D_241210, 0, 1, D_L39_00268C40) == 0) {
                D_1A43E0.sub = 1;
            }
            break;
        case 1:
            if (D_1A43E0.result == 1) {
                func_120048(workspace.name, D_L39_00243108, D_2411F8, D_L39_00268C60);
                if (func_13BD00(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, workspace.name) == 0) {
                    D_1A43E0.sub = 2;
                }
            } else {
                if (D_1A43E0.result == 0) {
                    D_1A43E0.sub = 3;
                } else {
                    D_1A43E0.err_card = D_1A43E0.cur;
                    if (D_1A43E0.result == -5) {
                        D_1A43E0.err = 0x10;
                    } else if (D_1A43E0.result == -4) {
                        D_1A43E0.err = 0xF;
                    } else if (D_1A43E0.result == -2) {
                        D_1A43E0.err = 0xE;
                    } else {
                        D_1A43E0.err = 0x12;
                    }
                    D_1A43E0.state = 0;
                    D_1A43E0.cur = 0;
                }
                D_1A43E0.busy = 0;
            }
            break;
        case 2:
            if (func_13BAD8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, D_241210, 1, 1, D_L39_00268C40) == 0) {
                D_1A43E0.sub = 1;
            }
            break;
        case 3:
            if (func_13BD00(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, D_2411F8) == 0) {
                D_1A43E0.sub = 4;
            }
            break;
        case 4:
            if (D_1A43E0.result != 0) {
                D_1A43E0.err_card = D_1A43E0.cur;
                if (D_1A43E0.result == -6) {
                    D_1A43E0.err = 0x11;
                } else if (D_1A43E0.result == -5) {
                    D_1A43E0.err = 0x10;
                } else if (D_1A43E0.result == -4) {
                    D_1A43E0.err = 0xF;
                } else if (D_1A43E0.result == -2) {
                    D_1A43E0.err = 0xE;
                } else {
                    D_1A43E0.err = 0x12;
                }
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        }
        break;

    case 21:
        D_1A43E0.state = 22;
        D_1A43E0.card[D_1A43E0.cur].tries = -1;
        D_1A43E0.index = 0;
        break;

    case 22:
        D_1A43E0.card[D_1A43E0.cur].tries++;
        if (D_1A43E0.card[D_1A43E0.cur].tries < 4) {
            D_1A43E0.sub = 0;
            D_1A43E0.state = 23;
        } else {
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
        }
        break;
    case 13:
        if (D_1A43E0.card[D_1A43E0.cur].status < 0) {
            D_1A43E0.err = 0x13;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        }
        D_1A43E0.index = 0;
        D_1A43E0.sub = 0;
        D_1A43E0.state = 14;
    case 14:
    case 23:
        switch (D_1A43E0.sub) {
        case 0:
            if (D_1A43E0.state == 23) {
                func_120048(workspace.name, D_2412B8, D_1A43E0.card[D_1A43E0.cur].tries);
            } else {
                func_120048(workspace.name, D_2412B8, D_1A43E0.card[D_1A43E0.cur].status);
            }
            if (func_13B1F8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, workspace.name, 1) == 0) {
                D_1A43E0.sub++;
            }
            break;
        case 1:
            if (D_1A43E0.result >= 0) {
                D_1A43E0.fd = D_1A43E0.result;
                D_1A43E0.sub = 2;
            } else {
                D_1A43E0.err_card = D_1A43E0.cur;
                if (D_1A43E0.result == -7) {
                    D_1A43E0.err = 0x14;
                } else if (D_1A43E0.result == -5) {
                    D_1A43E0.err = 0x15;
                } else if (D_1A43E0.result == -4) {
                    D_1A43E0.err = 0x16;
                } else if (D_1A43E0.result == -3) {
                    D_1A43E0.err = 0x17;
                } else if (D_1A43E0.result == -2) {
                    D_1A43E0.err = 0x18;
                } else {
                    D_1A43E0.err = 0x1C;
                }
                D_1A43E0.state = 0;
                D_1A43E0.cur = 0;
            }
            D_1A43E0.busy = 0;
            break;
        case 2:
            D_1A43E0.size = 8;
            if (func_13B5A8(D_1A43E0.fd, &D_1A43E0.card[D_1A43E0.cur].x28, 8) == 0) {
                D_1A43E0.sub = 3;
            }
            break;
        case 3:
            if (D_1A43E0.result == D_1A43E0.size) {
                D_1A43E0.busy = 0;
                D_1A43E0.sub = 4;
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result >= 0) {
                D_1A43E0.err = 0x1B;
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.state = 0;
                    D_1A43E0.cur = 0;
                    D_1A43E0.busy = 0;
                }
                break;
            }
            if (D_1A43E0.result == -5) {
                D_1A43E0.err = 0x15;
            } else if (D_1A43E0.result == -4) {
                D_1A43E0.err = 0x19;
            } else if (D_1A43E0.result == -3) {
                D_1A43E0.err = 0x1A;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 0x18;
            } else {
                D_1A43E0.err = 0x1C;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 4:
            D_1A43E0.size = D_1A43E0.card[D_1A43E0.cur].x28;
            if (func_13B5A8(D_1A43E0.fd, D_21E260, D_1A43E0.size) == 0) {
                D_1A43E0.sub = 5;
            }
            break;
        case 5:
            if (D_1A43E0.result == D_1A43E0.size) {
                if (D_1A43E0.state == 23) {
                    func_L39_005A88B0(D_21E260, D_1A43E0.cur, D_1A43E0.card[D_1A43E0.cur].tries);
                    D_1A43E0.sub = 8;
                } else {
                    D_1A43E0.card[D_1A43E0.cur].x24 = func_L39_005A8968(D_21E260, D_21E260 + D_1A43E0.result, 0, D_L39_00499348);
                    D_1A43E0.sub = 6;
                }
                D_1A43E0.busy = 0;
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result >= 0) {
                D_1A43E0.err = 0x1B;
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.state = 0;
                    D_1A43E0.cur = 0;
                    D_1A43E0.busy = 0;
                }
                break;
            }
            if (D_1A43E0.result == -5) {
                D_1A43E0.err = 0x15;
            } else if (D_1A43E0.result == -4) {
                D_1A43E0.err = 0x19;
            } else if (D_1A43E0.result == -3) {
                D_1A43E0.err = 0x1A;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 0x18;
            } else {
                D_1A43E0.err = 0x1C;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 6:
            D_1A43E0.size = D_1A43E0.card[D_1A43E0.cur].x2C;
            if (func_13B5A8(D_1A43E0.fd, D_224260, D_1A43E0.size) == 0) {
                D_1A43E0.sub = 7;
            }
            break;
        case 7:
            if (D_1A43E0.result == D_1A43E0.size) {
                D_1A43E0.card[D_1A43E0.cur].x24 += func_L39_005A8968(D_224260, D_224260 + D_1A43E0.result, D_1A43E0.index, D_L39_004995D8);
                if (++D_1A43E0.index < 0x25) {
                    D_1A43E0.sub = 6;
                } else {
                    D_1A43E0.sub = 8;
                }
                D_1A43E0.busy = 0;
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result >= 0) {
                D_1A43E0.err = 0x1B;
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.state = 0;
                    D_1A43E0.cur = 0;
                    D_1A43E0.busy = 0;
                }
                break;
            }
            if (D_1A43E0.result == -5) {
                D_1A43E0.err = 0x15;
            } else if (D_1A43E0.result == -4) {
                D_1A43E0.err = 0x19;
            } else if (D_1A43E0.result == -3) {
                D_1A43E0.err = 0x1A;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 0x18;
            } else {
                D_1A43E0.err = 0x1C;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 8:
            if (func_13B358(D_1A43E0.fd) == 0) {
                if (D_1A43E0.state == 23) {
                    D_1A43E0.busy = 0;
                    D_1A43E0.state = 22;
                } else {
                    finished_card = &D_1A43E0;
                    func_L39_005A8CC8();
                    if (finished_card->card[finished_card->cur].x24 != 0) {
                        finished_card->err = 0x1C;
                    }
                    finished_card->state = 0;
                    finished_card->cur = 0;
                }
            }
            break;
        }
        break;

    case 15:
        if (D_1A43E0.card[D_1A43E0.cur].x24 != 0) {
            D_1A43E0.busy = 0;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.err = 0x2717;
            break;
        }
        if (D_1A43E0.card[D_1A43E0.cur].status < 0) {
            D_1A43E0.busy = 0;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.err = 0x1D;
            break;
        }
        D_1A43E0.sub = 0;
        D_1A43E0.state = 16;
    case 16:
        switch (D_1A43E0.sub) {
        case 0:
            func_120048(workspace.name, D_2412B8, D_1A43E0.card[D_1A43E0.cur].status);
            if (func_13B1F8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, workspace.name, 2) == 0) {
                D_1A43E0.sub = 1;
            }
            break;
        case 1:
            if (D_1A43E0.result >= 0) {
                D_1A43E0.fd = D_1A43E0.result;
                D_1A43E0.sub = 2;
            } else {
                D_1A43E0.err_card = D_1A43E0.cur;
                if (D_1A43E0.result == -7) {
                    D_1A43E0.err = 0x1E;
                } else if (D_1A43E0.result == -5) {
                    D_1A43E0.err = 0x1F;
                } else if (D_1A43E0.result == -4) {
                    D_1A43E0.err = 0x20;
                } else if (D_1A43E0.result == -3) {
                    D_1A43E0.err = 0x21;
                } else if (D_1A43E0.result == -2) {
                    D_1A43E0.err = 0x22;
                } else {
                    D_1A43E0.err = 0x26;
                }
                D_1A43E0.state = 0;
                D_1A43E0.cur = 0;
            }
            D_1A43E0.busy = 0;
            break;
        case 2:
            if (func_13B418(D_1A43E0.fd, 8, 0) == 0) {
                D_1A43E0.sub = 3;
            }
            break;
        case 3:
            if (D_1A43E0.result >= 0) {
                D_1A43E0.sub = 4;
            } else if (func_13B358(D_1A43E0.fd) == 0) {
                D_1A43E0.err = 0x26;
                D_1A43E0.state = 0;
                D_1A43E0.cur = 0;
                D_1A43E0.busy = 0;
            }
            break;
        case 4:
            if (func_13B6C0(D_1A43E0.fd, D_21E260, func_0039E6A8(D_L39_00499348)) == 0) {
                D_1A43E0.sub = 5;
            }
            break;
        case 5:
            if (D_1A43E0.result == func_0039E6A8(D_L39_00499348)) {
                D_1A43E0.sub = 6;
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result >= 0) {
                finished_card = &D_1A43E0;
                finished_card->err = 0x25;
                if (func_13B358(finished_card->fd) == 0) {
                    finished_card->busy = 0;
                    goto reset_state;
                }
                break;
            }
            if (D_1A43E0.result == -5) {
                D_1A43E0.err = 0x1F;
            } else if (D_1A43E0.result == -4) {
                D_1A43E0.err = 0x23;
            } else if (D_1A43E0.result == -3) {
                D_1A43E0.err = 0x24;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 0x22;
            } else {
                D_1A43E0.err = 0x26;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 6:
            if (func_13B418(D_1A43E0.fd, D_1A43E0.card[0].x28 + (D_1A43E0.index * D_1A43E0.card[0].x2C + 8), 0) == 0) {
                D_1A43E0.sub = 7;
            }
            break;
        case 7:
            finished_card = &D_1A43E0;
            if (D_1A43E0.result == D_1A43E0.card[0].x28 + 8 + D_1A43E0.index * D_1A43E0.card[0].x2C) {
                D_1A43E0.sub = 8;
            } else {
                if (func_13B358(finished_card->fd) == 0) {
                    finished_card->busy = 0;
                    goto reset_state;
                }
            }
            break;
        case 8:
            if (func_13B6C0(D_1A43E0.fd, D_224260, func_0039E6A8(D_L39_004995D8)) == 0) {
                D_1A43E0.sub = 9;
            }
            break;
        case 9:
            if (D_1A43E0.result == func_0039E6A8(D_L39_004995D8)) {
                D_1A43E0.sub = 10;
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result >= 0) {
                finished_card = &D_1A43E0;
                finished_card->err = 0x25;
                if (func_13B358(finished_card->fd) == 0) {
                    finished_card->busy = 0;
                reset_state:
                    finished_card->cur = 0;
                    finished_card->state = 0;
                }
                break;
            }
            if (D_1A43E0.result == -5) {
                D_1A43E0.err = 0x1F;
            } else if (D_1A43E0.result == -4) {
                D_1A43E0.err = 0x23;
            } else if (D_1A43E0.result == -3) {
                D_1A43E0.err = 0x24;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 0x18;
            } else {
                D_1A43E0.err = 0x1C;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 10:
            finished_card = &D_1A43E0;
            if (func_13B358(finished_card->fd) == 0) {
                finished_card->state = 0;
                finished_card->cur = 0;
            }
            break;
        }
        break;

    case 17: {
        McChunk_005A61D8 *chunk;
        func_L39_0059A218(D_1F0A00.x664 << 11, &chunk);
        func_L39_005C29A0(chunk, D_1F0A00.x660 + D_1F0A00.x64C, D_1F0A00.x664);
        D_1A43E0.state = 18;
        D_1A43E0.busy = 0;
        break;
    }

    case 18:
        if (*(s16 *)0x225664 == 0) {
            McChunk_005A61D8 *chunk;
            func_L39_0059A218(*(s32 *)0x1F1064 << 11, &chunk);
            D_1A43E0.state = 19;
            D_1A43E0.buf = (u8 *)chunk + chunk->x10;
        }
        D_1A43E0.busy = 0;
        break;

    case 19:
        if (D_1A43E0.card[D_1A43E0.cur].x24 != 0) {
            D_1A43E0.busy = 0;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.err = 0x2718;
            break;
        }
        if (D_1A43E0.card[D_1A43E0.cur].status < 0) {
            D_1A43E0.busy = 0;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.err = 0x27;
            break;
        }
        D_1A43E0.index = 0;
        D_1A43E0.sub = 0;
        D_1A43E0.state = 20;
    case 20:
        switch (D_1A43E0.sub) {
        case 0:
            func_120048(workspace.name, D_2412B8, D_1A43E0.card[D_1A43E0.cur].status);
            if (func_13B1F8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, workspace.name, 2) == 0) {
                D_1A43E0.sub = 1;
            }
            break;
        case 1:
            if (D_1A43E0.result >= 0) {
                s32 n;

                D_1A43E0.fd = D_1A43E0.result;
                n = func_0039E6A8(D_L39_00499348);
                D_1A43E0.size = n + func_0039E6A8(D_L39_004995D8) * 0x25 + 8;
                if (func_13B6C0(D_1A43E0.fd, D_1A43E0.buf, D_1A43E0.size) == 0) {
                    D_1A43E0.sub = 2;
                }
                break;
            }
            D_1A43E0.err = 0x2B;
            D_1A43E0.err_card = D_1A43E0.cur;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 2:
            if (D_1A43E0.result == D_1A43E0.size) {
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.sub = 3;
                }
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result >= 0) {
                D_1A43E0.err = 0xB;
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.state = 0;
                    D_1A43E0.cur = 0;
                    D_1A43E0.busy = 0;
                }
                break;
            }
            if (D_1A43E0.result == -4) {
                D_1A43E0.err = 0x28;
            } else if (D_1A43E0.result == -3) {
                D_1A43E0.err = 0x29;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 0x2A;
            } else {
                D_1A43E0.err = 0x2D;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 3:
            if (D_1A43E0.result != 0) {
                D_1A43E0.err = 0x2C;
                D_1A43E0.err_card = D_1A43E0.cur;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        }
        break;

    case 32:
        D_1A43E0.state = 33;
        D_1A43E0.index = 0;
        D_1A43E0.sub = 0;
    case 33:
        switch (D_1A43E0.sub) {
        case 0:
            if (func_13B1F8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, D_241298, 1) == 0) {
                D_1A43E0.sub = 1;
            }
            break;
        case 1:
            if (D_1A43E0.result >= 0) {
                s32 n;

                D_1A43E0.fd = D_1A43E0.result;
                D_1A43E0.buf = D_21E260;
                n = func_0039E6A8(&D_L39_001D79B8);
                D_1A43E0.size = n;
                if (func_13B5A8(D_1A43E0.fd, D_1A43E0.buf, n) == 0) {
                    D_1A43E0.sub = 2;
                }
                break;
            }
            D_1A43E0.err = 0x2E;
            D_1A43E0.err_card = D_1A43E0.cur;
            D_1A43E0.busy = 0;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            break;
        case 2:
            if (D_1A43E0.result == D_1A43E0.size) {
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.sub = 3;
                }
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result >= 0) {
                D_1A43E0.err = 0x2F;
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.busy = 0;
                    D_1A43E0.state = 0;
                    D_1A43E0.cur = 0;
                }
                break;
            }
            if (D_1A43E0.result == -5) {
                D_1A43E0.err = 0x30;
            } else if (D_1A43E0.result == -4) {
                D_1A43E0.err = 0x31;
            } else if (D_1A43E0.result == -3) {
                D_1A43E0.err = 0x32;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 0x33;
            } else {
                D_1A43E0.err = 0x34;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 3:
            if (D_1A43E0.result != 0) {
                D_1A43E0.err = 0x35;
                D_1A43E0.err_card = D_1A43E0.cur;
            } else {
                D_1A43E0.card[D_1A43E0.cur].x24 = func_L39_005A8968(D_21E260, D_21E260 + D_1A43E0.size, 0, &D_L39_001D79B8);
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        }
        break;

    case 34:
        D_1A43E0.state = 35;
        D_1A43E0.index = 0;
        D_1A43E0.sub = 0;
    case 35:
        switch (D_1A43E0.sub) {
        case 0:
            if (func_13B1F8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, D_241298, 2) == 0) {
                D_1A43E0.sub = 1;
            }
            break;
        case 1:
            if (D_1A43E0.result >= 0) {
                s32 n;

                D_1A43E0.fd = D_1A43E0.result;
                n = func_0039E6A8(&D_L39_001D79B8) + 8;
                D_1A43E0.size = n;
                if (func_13B6C0(D_1A43E0.fd, D_1A43E0.buf, n) == 0) {
                    D_1A43E0.sub = 2;
                }
                break;
            }
            D_1A43E0.err = 0x36;
            D_1A43E0.err_card = D_1A43E0.cur;
            D_1A43E0.busy = 0;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            break;
        case 2:
            if (D_1A43E0.result == D_1A43E0.size) {
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.sub = 3;
                }
                break;
            }
            D_1A43E0.err_card = D_1A43E0.cur;
            if (D_1A43E0.result >= 0) {
                D_1A43E0.err = 0x37;
                if (func_13B358(D_1A43E0.fd) == 0) {
                    D_1A43E0.busy = 0;
                    D_1A43E0.state = 0;
                    D_1A43E0.cur = 0;
                }
                break;
            }
            if (D_1A43E0.result == -4) {
                D_1A43E0.err = 0x38;
            } else if (D_1A43E0.result == -3) {
                D_1A43E0.err = 0x39;
            } else if (D_1A43E0.result == -2) {
                D_1A43E0.err = 0x3A;
            } else {
                D_1A43E0.err = 0x3B;
            }
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        case 3:
            if (D_1A43E0.result != 0) {
                D_1A43E0.err = 0x3C;
                D_1A43E0.err_card = D_1A43E0.cur;
            }
            D_1A43E0.busy = 0;
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            break;
        }
        break;

    case 24:
        D_1A43E0.state = 25;
        D_1A43E0.sub = 0;
        D_1A43E0.card[D_1A43E0.cur].x1C = 1;
    case 25:
        switch (D_1A43E0.sub / 5) {
        case 0:
            func_120048(workspace.name, D_L39_00243110, D_1A43E0.sub % 5);
            break;
        case 1:
            func_120048(workspace.name, D_L39_00243130, D_1A43E0.sub % 5);
            break;
        case 2:
            func_120048(workspace.name, D_L39_00243150, D_1A43E0.sub % 5);
            break;
        case 3:
            workspace.name[0] = 0;
            break;
        }
        if ((u8)workspace.name[0] == 0) {
            D_1A43E0.state = 28;
            D_1A43E0.busy = 0;
            break;
        }
        if (func_13B1F8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, workspace.name, 1) == 0)
            D_1A43E0.state = 26;
        break;

    case 26:
        if (D_1A43E0.result >= 0) {
            D_1A43E0.fd = D_1A43E0.result;
            if (func_13B5A8(D_1A43E0.result, D_21E260, 0x2800) == 0)
                D_1A43E0.state = 27;
        } else {
            D_1A43E0.state = 25;
            D_1A43E0.sub = (D_1A43E0.sub / 5 + 1) * 5;
            D_1A43E0.busy = 0;
        }
        break;

    case 27:
        if (D_1A43E0.result >= 0x2800) {
            if (func_13B358(D_1A43E0.fd) != 0)
                break;
            if (func_0039E788(D_21E268) != 0) {
                s32 *p = D_21E268 + 2;
                if (*p != -1) {
                    do {
                        if (p[0] == 0xA) {
                            D_1A4610.flags |= 0x40;
                            if (((u8 *)p)[0x27] != 0) {
                                D_1A4610.flags |= 1;
                                D_1A43E0.card[D_1A43E0.cur].x1C++;
                            }
                            break;
                        }
                        p = (s32 *)((u8 *)p + (((p[1] + 3) / 4) * 4 + 8));
                    } while (*p != -1);
                }
            }
            D_1A43E0.sub++;
        } else {
            D_1A43E0.sub = (D_1A43E0.sub / 5 + 1) * 5;
        }
        D_1A43E0.state = 25;
        D_1A43E0.busy = 0;
        break;

    case 28:
        D_1A43E0.state = 29;
        D_1A43E0.sub = 0;
        D_1A43E0.card[D_1A43E0.cur].x1C++;
    case 29:
        switch (D_1A43E0.sub / 5) {
        case 0:
            func_120048(workspace.name, D_L39_00243170, D_1A43E0.sub % 4);
            break;
        case 1:
            func_120048(workspace.name, D_L39_00243190, D_1A43E0.sub % 4);
            break;
        case 2:
            func_120048(workspace.name, D_L39_002431B0, D_1A43E0.sub % 4);
            break;
        case 3:
            func_120048(workspace.name, D_L39_002431D0, D_1A43E0.sub % 4);
            break;
        case 4:
            workspace.name[0] = 0;
            break;
        }
        if ((u8)workspace.name[0] == 0) {
            D_1A43E0.state = 0;
            D_1A43E0.cur = 0;
            D_1A43E0.busy = 0;
            break;
        }
        if (func_13B1F8(D_1A43E0.card[D_1A43E0.cur].port, D_1A43E0.card[D_1A43E0.cur].slot, workspace.name, 1) == 0)
            D_1A43E0.state = 30;
        break;

    case 30:
        if (D_1A43E0.result >= 0) {
            D_1A43E0.fd = D_1A43E0.result;
            if (func_13B5A8(D_1A43E0.result, D_21E260, 0x2800) == 0)
                D_1A43E0.state = 31;
        } else {
            D_1A43E0.state = 29;
            D_1A43E0.sub = (D_1A43E0.sub / 5 + 1) * 5;
            D_1A43E0.busy = 0;
        }
        break;

    case 31:
        if (D_1A43E0.result >= 0x2800) {
            if (func_13B358(D_1A43E0.fd) != 0)
                break;
            if (func_0039E788(D_21E268) != 0) {
                s32 *p = D_21E268 + 2;
                if (*p != -1) {
                    do {
                        if (p[0] == 0xA) {
                            u8 *b = (u8 *)(p + 2);
                            D_1A4610.flags |= 0x80;
                            if (b[0x29] != 0) {
                                D_1A4610.flags |= 2;
                                D_1A43E0.card[D_1A43E0.cur].x1C++;
                            }
                            if (b[0x1D] != 0) {
                                D_1A4610.flags |= 4;
                                D_1A43E0.card[D_1A43E0.cur].x1C++;
                            }
                            if (b[0x25] != 0) {
                                D_1A4610.flags |= 8;
                                D_1A43E0.card[D_1A43E0.cur].x1C++;
                            }
                            if (b[0x2D] != 0) {
                                D_1A4610.flags |= 0x10;
                                D_1A43E0.card[D_1A43E0.cur].x1C++;
                            }
                            if (b[0x1C] != 0) {
                                D_1A4610.flags |= 0x20;
                                D_1A43E0.card[D_1A43E0.cur].x1C++;
                            }
                            break;
                        }
                        p = (s32 *)((u8 *)p + (((p[1] + 3) / 4) * 4 + 8));
                    } while (*p != -1);
                }
            }
            D_1A43E0.sub++;
        } else {
            D_1A43E0.sub = (D_1A43E0.sub / 5 + 1) * 5;
        }
        D_1A43E0.state = 29;
        D_1A43E0.busy = 0;
        break;
    }
}
