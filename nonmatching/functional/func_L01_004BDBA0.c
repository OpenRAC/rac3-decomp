/* functional: medium. Rewritten from PAL asm; ~209 words differ from retail through scheduling and branch layout. */
/* localdecomp:start func_L01_004BDBA0 */
typedef struct { s32 id; u8 type; u8 pad5[13]; u8 locked; u8 other; } Ent_BDBA0;
typedef struct {
    u8 pad0[0x28]; s32 sound; u8 pad2C[0x24];
    s32 mode; u8 pad54[8]; s32 f5C; u8 pad60[12];
    s32 scroll; u8 pad70[8]; s32 handle; s32 f7C; s32 selected; s32 active;
    u8 f88; u8 pad89[3]; s32 f8C; u8 pad90[0xB0];
    Ent_BDBA0 entries[76]; u8 pad730[16]; s32 count; u8 pad744[16];
    s32 cost; u8 f758; u8 pad759[3]; s32 f75C; s32 f760;
} UI_BDBA0;
typedef struct { u8 pad0[0x1C4]; s32 buttons; } Pad_BDBA0;
typedef struct { u8 enabled; u8 pad1[0x37]; u16 f38; u8 pad3A[0x4A]; u16 cost; u8 pad86[4]; u16 max; u8 pad8C[0x64]; } Item_BDBA0;
extern S_00244740 D_L01_002446C0[];
extern Pad_BDBA0 *D_001D52FC_sda;
extern Pad_BDBA0 *D_L01_001D52FC;
__asm__(".extern D_L01_001D52FC, 16");
extern s32 D_001E0F90_sda;
extern s32 D_001D545C_sda;
extern u8 D_001DABC8_sda;
extern s32 D_001DABCC_sda;
extern s32 D_001DABD0_sda;
extern s32 D_001DABD8_sda;
extern s16 D_001426A0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern u8 D_00142CA0[];
extern S_002C5640 D_L01_002C5600[];
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern void func_003BA4F8(s32 *, s32);
extern void func_003A52A0(s32, s32, s32);
extern void func_003A2750(s32);
extern void func_003935B0(s32, s32);
extern s32 func_L01_004BB0F0(s32);
extern void func_L01_004C4E60(void);
extern void func_L01_005147A8(s32);
extern void func_L01_00425978(s32);
extern void func_L01_004BD170(void);
extern void func_L01_0047B798(s32, s32);
extern void func_L01_0047B820(s32, s32);
extern void func_L01_0047B9B8(s32);

void func_L01_004BDBA0(void) {
    UI_BDBA0 *u = (UI_BDBA0 *)D_L01_002446C0;
    Pad_BDBA0 *p;
    s32 changed = 0;
    s32 prev;
    s32 cur;
    s32 id;
    Item_BDBA0 *it;

    if (!u->active) {
        prev = func_003B9C58(func_003B9BD0(0));
        func_003BA4F8(func_003B9BD0(0), D_L01_001D52FC->buttons);
        cur = func_003B9C58(func_003B9BD0(0));
        if (prev != cur) {
            u->selected = cur;
            changed = 1;
        }
        if (changed) {
            if (u->f88) u->f8C = (u->mode != 2) ? 1 : 3;
            if (u->handle != -1 && u->mode == 0) func_003935B0(u->handle, 0);
            u->handle = -1;
        }
        if ((D_001D52FC_sda->buttons & 0x40) && !(D_001E0F90_sda & 0x40)) {
            s32 *ent = (s32 *)((u8 *)u + 0x148 + (u->selected << 4));
            if (func_L01_004BB0F0(*ent) != 0) {
                D_001DABC8_sda = 1;
                D_001DABD0_sda = *ent;
                func_L01_004C4E60();
                if (D_001DABD0_sda == -1) {
                    func_L01_005147A8(D_001DABCC_sda);
                } else {
                    id = *(s32 *)((u8 *)u + 0x148 + (u->selected << 4));
                    D_001DABCC_sda = id;
                    func_L01_005147A8(id);
                }
                func_L01_00425978(D_001426A0[0]);
                func_003A2750(1);
            } else {
                u->active = 1;
            }
            if (u->mode == 3 || u->mode == 5) func_003A52A0(0, 17, u->sound);
        }
        if (D_001D545C_sda == 3 && !u->f5C && !u->entries[u->selected].locked && !u->entries[u->selected].other) {
            id = u->entries[u->selected].id;
            if (id != 0x67 && id != 0x16 && u->mode == 0 && (D_L01_001D52FC->buttons & 0x80)) {
                D_001DABD8_sda = 0;
                u->f758 = 1;
                u->f760 = id;
                u->f75C = id;
                func_L01_004BD170();
            }
        }
        if (D_001D52FC_sda->buttons & 0x10) func_L01_004BD170();
    }
    if (u->entries[u->selected].type == 1) {
        id = u->entries[u->selected].id;
        it = (Item_BDBA0 *)((u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0);
        if (it->enabled && D_00142CA0[id]) {
            func_L01_0047B798(it->f38, 0);
            func_L01_0047B820(D_001427F0[id], it->max);
            func_L01_0047B9B8(id);
        }
    }
}
/* localdecomp:end func_L01_004BDBA0 */
