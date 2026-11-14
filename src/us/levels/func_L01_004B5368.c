#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_004B5368 */
typedef struct { u8 pad0[0xAA]; s16 id; } Obj_004B5368;
typedef struct {
    u8 pad0[0x1E0];
    s16 land_lockout;
    u8 pad1E2[0x121C - 0x1E2];
    u8 b121C;
    u8 pad121D[0x1228 - 0x121D];
    s32 held_item;
    u8 pad122C[0x19E0 - 0x122C];
    Obj_004B5368 *obj;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 state;
    u8 pad25C8[4];
    s32 state_type;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 body_kind;
    u8 pad25E5[0x25F2 - 0x25E5];
    u8 death_reported;
} Hero_004B5368;
typedef struct {
    u8 pad0[0x1A4];
    s32 w1A4;
    u8 pad1A8[8];
    s32 w1B0;
} Pad_004B5368;
typedef struct { u16 count; u16 pad; u32 maximum; u32 levels; } Stat_004B5368;

extern s32 D_L01_001D6694_004B5368;
extern u8 D_L01_001D672D_004B5368;
extern s32 D_001D4CEC_sda_004B5368;
__asm__(".extern D_001D4CEC_sda_004B5368, 4");
extern s32 D_001D6694_sda_004B5368;
__asm__(".extern D_001D6694_sda_004B5368, 4");
extern Hero_004B5368 D_001A4BE0;
extern Pad_004B5368 *D_001D52FC;
extern Pad_004B5368 *D_001D52FC_sda;
extern s32 D_L01_001DFBC8;
extern s32 D_001DFBC8_sda;
__asm__(".extern D_001DFBC8_sda, 4");
extern s32 D_001DAB6C_sda;
__asm__(".extern D_001DAB6C_sda, 4");
extern u8 D_001DAB70_sda;
__asm__(".extern D_001DAB70_sda, 4");
extern f32 D_L01_001DF9D0;
extern s32 D_L01_002D1630[];
extern u8 D_00143A06[];
extern s32 D_L01_001DBD00;
extern s32 D_L01_001DBCFC;
extern s32 D_001DBD04_sda;
__asm__(".extern D_001DBD04_sda, 4");
extern u8 D_001D4CF4;
extern s32 D_001D545C;
extern s32 D_001D545C_sda_004B5368;
__asm__(".extern D_001D545C_sda_004B5368, 4");
extern s32 D_L01_001D673C_004B5368;
extern s32 D_001D6740_sda;
__asm__(".extern D_001D6740_sda, 4");
extern Stat_004B5368 D_001A7C10[];
extern s32 D_001D4C38;
extern s32 D_001D4C38;
extern s32 D_L01_001DFCA8;
extern s32 D_L01_001D6698;
extern s32 D_00142660[];
extern u8 D_L01_001D7EA0[];

extern s32 func_0039BEC0(s32, s32, s32, s32, s32);
extern s32 func_L01_004300C0(void);
extern s32 func_L01_004300D8(void);
extern s32 func_L01_004B5360_004B5368(void);
extern s32 func_L01_005103A0_004B5368(void);
extern s32 func_L01_005103A8_004B5368(void);
extern s32 func_L01_005103E8(s32);
extern s32 func_L01_005104B8(void);
extern s32 func_L01_0041FD50(void);
extern void func_00393430(void);
extern s32 func_00393448(void);
extern void func_L01_00503668(void);
extern s32 func_L01_00457230_004B5368(void);
extern s32 func_L01_00417EC8(s32);
extern s32 func_L01_003EE980_004B5368(void);
extern void func_L01_00457268(s32);
extern void func_L01_0047A230_004B5368(void);
extern void func_L01_0044F290(void);
extern void func_003DF7C0(s32);
extern void func_003DFF90(s32);
extern void func_003DFFD0(void);
extern void func_L01_004C4F88(void);
extern void func_L01_00435DE0(void);
extern void func_003C7AE8(void);
extern void func_L01_004A76F0(void);
extern void func_L01_004DE348(void);
extern void func_003C7DE0(void);
extern void func_00380AB0(void);
extern void func_L01_004A6468(void);
extern void func_0039EE68(void);
extern void func_003CB5B0(void);
extern void func_L01_00437AB8(void);
extern void func_00391D08(s32);
extern void func_003A9EF0(void);
extern void func_L01_00475040(void);
extern void func_L01_00475078(s32);
extern void func_L01_00418478(void);
extern void func_003E0068(void);

void func_L01_004B5368(void) {
    s32 flag;
    s32 a1;
    s32 b;
    s32 t;
    s32 i;

    if (D_L01_001D6694_004B5368 == 0 && D_L01_001D672D_004B5368 == 0 && (D_001D4CEC_sda_004B5368 & 1)) {
        func_0039BEC0(4, 1, 1, 0, 0);
        return;
    }
    if (func_L01_004300C0() && D_001D6694_sda_004B5368 == 0 && (D_001D4CEC_sda_004B5368 & 0x600)) {
        if (func_0039BEC0(4, 1, 1, 0, 0) == 0) return;
    }
    if (func_L01_004300D8() && D_001D6694_sda_004B5368 == 0 && func_L01_004300C0()) {
        if (func_0039BEC0(4, 1, 1, 0, 0) == 0) return;
    }
    if (func_L01_004B5360_004B5368()) return;

    flag = D_001A4BE0.state != 0x31;
    a1 = 0;
    if (D_001A4BE0.obj) {
        s32 id = D_001A4BE0.obj->id;
        if (id == 0x905 || id == 0x85C || id == 0xEEF || id == 0x10EE) a1 = 1;
    }
    flag |= a1;
    b = 0;
    if (D_001A4BE0.obj) b = D_001A4BE0.obj->id == 0x1A17;
    flag |= b;
    flag = (flag != 0) | (func_L01_005103A0_004B5368() != 0);
    flag |= func_L01_005103E8(3) != 0;
    flag |= func_L01_005103E8(5) != 0;
    flag |= func_L01_005104B8() != 0;
    func_L01_0041FD50();

    if ((D_001D52FC->w1B0 & 0x10) && !(D_001D52FC->w1A4 & 0x10) && D_L01_001DFBC8 >= 8
        && !D_001A4BE0.death_reported && D_001A4BE0.state != 0x74 && D_001A4BE0.state != 0x58
        && D_001A4BE0.state != 0x39 && D_001A4BE0.b121C != 2 && D_001A4BE0.state != 0x31 && flag
        && D_001A4BE0.state != 0x1C && D_001D6694_sda_004B5368 == 0 && D_L01_001DF9D0 < 0.2f
        && (D_001A4BE0.body_kind < 2 || D_001A4BE0.body_kind == 3) && D_L01_002D1630[0] == 0
        && D_00143A06[0] != 0) {
        D_001DAB6C_sda = D_001DAB6C_sda + 1;
        if (D_001DAB6C_sda >= 3) D_001DAB6C_sda = 2;
        if (D_001DAB6C_sda >= 2) {
            func_00393430();
            if (func_00393448()) {
                if (D_001A4BE0.body_kind != 1) func_L01_00503668();
                func_0039BEC0(4, 1, 7, 0, 0);
                t = D_L01_001DBD00;
                D_001DBD04_sda = t;
                D_L01_001DBCFC = t;
                goto done;
            }
        }
    } else {
        D_001DAB6C_sda = 0;
    }

    if (!func_L01_00457230_004B5368()
        && ((D_001D52FC->w1A4 & 0x800) || D_001D4CF4) && D_001DFBC8_sda >= 8
        && D_001A4BE0.state != 0x74 && D_001A4BE0.state != 0x58
        && !(D_001A4BE0.b121C == 2 && D_001A4BE0.held_item != 9)
        && flag && D_001D6694_sda_004B5368 == 0 && D_001A4BE0.land_lockout == 0) {
        if (D_001DAB70_sda) {
            func_0039BEC0(3, 1, 8, 0, 0);
        } else if (func_L01_00417EC8(D_001D545C_sda_004B5368)) {
            func_0039BEC0(3, 1, 5, 0, 0);
        } else {
            func_0039BEC0(3, 1, 1, 0, 0);
        }
        func_L01_00457268(func_L01_003EE980_004B5368() != 0);
        func_L01_0047A230_004B5368();
        return;
    }

    if (D_001A4BE0.land_lockout == 0 && D_L01_001DFBC8 >= 8
        && (D_001D52FC->w1A4 & 0x500) && D_001A4BE0.state_type != 0x16
        && D_001A4BE0.state != 0x74 && D_001A4BE0.state != 0x58
        && flag
        && D_001A4BE0.state != 0x1C
        && D_001A4BE0.state != 0xB0 && D_001A4BE0.state != 0x16 && D_001A4BE0.state != 0x39
        && D_001D6694_sda_004B5368 == 0
        && (!func_L01_005103A0_004B5368() || !func_L01_005103A8_004B5368())
        && !func_L01_00417EC8(D_001D545C_sda_004B5368)) {
        if (D_L01_001D673C_004B5368 != 0 && D_001D6740_sda == 0) {
            if (D_001D545C == 0x1A || (D_001A4BE0.state != 0x5F && D_001A4BE0.state != 0x5C))
                func_0039BEC0(4, 1, 6, 0, 0);
            if (D_001A7C10[35].count < 0xFFFF) D_001A7C10[35].count++;
            if (D_001D4C38 > D_001A7C10[35].maximum) D_001A7C10[35].maximum = D_001D4C38;
            D_001A7C10[35].levels = (D_001A7C10[35].levels | (1u << D_001D545C)) | 0x80000000u;
        } else {
            func_0039BEC0(3, 1, 2, 0, 0);
            func_L01_00457268(func_L01_003EE980_004B5368() != 0);
            if (D_001A7C10[9].count < 0xFFFF) D_001A7C10[9].count++;
            if (D_001D4C38 > D_001A7C10[9].maximum) D_001A7C10[9].maximum = D_001D4C38;
            D_001A7C10[9].levels = (D_001A7C10[9].levels | (1u << D_001D545C)) | 0x80000000u;
        }
        goto done;
    }

    if (D_001A4BE0.state != 0x1C) func_L01_0044F290();
    if ((D_001D52FC->w1A4 & 0x200) && D_001A4BE0.state != 0x1C && D_001A4BE0.state != 0x31
        && D_001A4BE0.body_kind != 2) {
        if ((u32)(D_001D545C_sda_004B5368 - 0x1E) >= 6) {
            func_003DF7C0(0x168);
            func_003DFF90(0xB4);
        }
    }
    if (D_L01_001DFCA8) {
        if (!func_0039BEC0(6, 1, 0, 0, 0)) {
            func_L01_00457268(func_L01_003EE980_004B5368() != 0);
            D_L01_001DFCA8 = 0;
            goto done;
        }
    }
    func_003DFFD0();
    func_L01_004C4F88();
    func_L01_00435DE0();
    func_003C7AE8();
    func_L01_004A76F0();
    func_L01_004DE348();
    func_003C7DE0();
    qzero(D_L01_001D7EA0);
    func_00380AB0();
    if (D_L01_001D6698) func_L01_004A6468(); else func_0039EE68();
    func_003CB5B0();
    func_L01_00437AB8();
    if (D_00142660[0] > 99999999) D_00142660[0] = 99999999;
    func_00391D08(1);
    func_003A9EF0();
    func_L01_00475040();
    for (i = 0; i < 1; i++) func_L01_00475078(i);
    func_L01_00418478();
    func_003E0068();
done:
    return;
}
/* localdecomp:end func_L01_004B5368 */
