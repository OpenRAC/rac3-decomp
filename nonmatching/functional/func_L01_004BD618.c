/* functional: medium. Rewritten from PAL asm; NTSC-U draft used only for structure. Behaviour should match; 320 words differ due to scheduling/branch layout. */
/* localdecomp:start func_L01_004BD618 */
typedef struct { s32 id; u8 type; u8 pad5[13]; u8 locked; u8 other; } Ent_BD618;
typedef struct {
    u8 pad0[0x28]; s32 sound; u8 pad2C[0x24];
    s32 mode; u8 pad54[8]; s32 f5C; u8 pad60[12];
    s32 scroll; u8 pad70[8]; s32 handle; s32 f7C; s32 selected; s32 active;
    u8 f88; u8 pad89[3]; s32 f8C; u8 pad90[0xB0];
    Ent_BD618 entries[76]; u8 pad730[16]; s32 count; u8 pad744[16];
    s32 cost; u8 f758; u8 pad759[3]; s32 f75C; s32 f760;
} UI_BD618;
typedef struct { u8 pad0[0x1C4]; s32 buttons; } Pad_BD618;
typedef struct { u8 enabled; u8 pad1[0x37]; u16 f38; u8 pad3A[0x4A]; u16 cost; u8 pad86[4]; u16 max; u8 pad8C[0x64]; } Item_BD618;
extern S_00244740 D_L01_002446C0[];
extern s32 D_L01_001E0F60[];
extern s32 D_L01_001E0F8C[];
extern s32 D_L01_001E0F88[];
__asm__(".extern D_L01_001E0F8C, 16");
__asm__(".extern D_L01_001E0F88, 16");
extern s32 D_001E0F90_sda;
extern Pad_BD618 *D_001D52FC_sda;
extern Pad_BD618 *D_L01_001D52FC;
__asm__(".extern D_L01_001D52FC, 16");
extern s32 D_001D545C_sda;
extern s32 D_001DABA0_sda;
extern s32 D_001DABD8_sda;
extern u8 D_001DABDC_sda;
extern A_4BBAF0 D_00142660;
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern u8 D_00142CA0[];
extern S_002C5640 D_L01_002C5600[];
extern void func_003A52A0(s32, s32, s32);
extern void func_003935B0(s32, s32);
extern s32 func_L01_004BA830(void);
extern void func_L01_004BD170(void);
extern void func_L01_0047B798(s32, s32);
extern void func_L01_0047B820(s32, s32);
extern void func_L01_0047B9B8(s32);

void func_L01_004BD618(void) {
    UI_BD618 *u = (UI_BD618 *)D_L01_002446C0;
    Pad_BD618 *p;
    s32 changed;
    s32 old;
    s32 id;
    s32 money;
    s32 doAccept;
    Item_BD618 *it;

    if (!u->active && (u32)D_L01_001E0F60[0] < 2) {
        /* down */
        p = D_001D52FC_sda;
        if ((p->buttons & 0x2000) || (D_L01_001E0F8C[0] >= 16 && D_L01_001E0F8C[0] % 10 == 1)) {
            if (u->scroll < 57) {
                changed = 0;
                if (u->selected < u->count - 1) { u->selected++; changed = 1; }
                if (changed) {
                    if (u->f88) { u->f8C = 1; D_001DABA0_sda = 4; }
                    u->scroll += 56;
                    func_003A52A0(1, 17, u->sound);
                    if (u->handle != -1 && u->mode == 0) func_003935B0(u->handle, 0);
                    u->handle = -1;
                    p = D_L01_001D52FC;
                }
            }
        }
        /* up */
        if ((p->buttons & 0x8000) || (D_L01_001E0F88[0] >= 16 && D_L01_001E0F88[0] % 10 == 1)) {
            if (u->scroll >= -56) {
                changed = 0;
                if (u->selected > 0) { u->selected--; changed = 1; }
                if (changed) {
                    if (u->f88) u->f8C = 1;
                    u->scroll -= 56;
                    func_003A52A0(1, 17, u->sound);
                    if (u->handle != -1 && u->mode == 0) func_003935B0(u->handle, 0);
                    u->handle = -1;
                    p = D_L01_001D52FC;
                }
            }
        }
        /* accept */
        if (p->buttons & 0x40) {
            old = D_001E0F90_sda;
            if (!(old & 0x40)) {
                doAccept = 1;
                if (u->mode == 3 || u->mode == 5) {
                    if (*(s32 *)((u8 *)u + 0x144 + (u->selected << 4)) == 0) doAccept = 0;
                }
                if (doAccept) {
                    s32 ok = 0;
                    if (u->mode != 0) {
                        ok = 1;
                    } else {
                        if (!u->entries[u->selected].locked) {
                            if (u->entries[u->selected].type == 0) {
                                if (*(s32 *)&D_00142660 >= func_L01_004BA830()) ok = 1;
                            }
                            if (!ok && u->entries[u->selected].type == 1) {
                                s32 buy = u->entries[u->selected].id;
                                it = (Item_BD618 *)((u8 *)D_L01_002C5600 + D_001425C0[buy] * 0xF0);
                                if (D_001427F0[buy] < it->max && *(s32 *)&D_00142660 >= it->cost) ok = 1;
                            }
                        }
                        if (!ok) {
                            if (u->entries[u->selected].locked == 1 && u->cost != 0 && !(*(s32 *)&D_00142660 < u->cost)) ok = 1;
                            else func_003A52A0(2, 17, u->sound);
                        }
                    }
                    if (ok) {
                        u->active = 1;
                        if (u->mode == 3 || u->mode == 5) func_003A52A0(0, 17, u->sound);
                    }
                }
            }
        }
        if (D_001D545C_sda == 3 && !u->f5C && !u->entries[u->selected].locked && !u->entries[u->selected].other) {
            id = u->entries[u->selected].id;
            if (id != 0x67 && id != 0x16 && u->mode == 0 && (D_L01_001D52FC->buttons & 0x80)) {
                u->f758 = 1;
                u->f760 = id;
                u->f75C = id;
                if (D_001DABD8_sda) D_001DABDC_sda = 1;
                D_001DABD8_sda = 0;
                func_L01_004BD170();
            }
        }
        if (D_001D52FC_sda->buttons & 0x10) func_L01_004BD170();
    }
    if (u->entries[u->selected].type == 1) {
        id = u->entries[u->selected].id;
        it = (Item_BD618 *)((u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0);
        if (it->enabled && D_00142CA0[id]) {
            func_L01_0047B798(it->f38, 0);
            func_L01_0047B820(D_001427F0[id], ((Item_BD618 *)((u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0))->max);
            func_L01_0047B9B8(id);
        }
    }
}
/* localdecomp:end func_L01_004BD618 */
