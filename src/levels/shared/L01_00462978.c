#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00462978 */
typedef void (*Updater_462978)();
extern Updater_462978 D_L01_00220E40[];
extern void func_L01_00461B28();
extern void func_L01_00461C20();
extern void func_L01_00463038();
extern void func_L01_004632D0();
extern void func_L01_00463538();
extern void func_L01_004637C0_00462978();
extern void func_L01_004638C8();
extern void func_L01_004639C8();
extern void func_L01_00463A70();
extern void func_L01_00464178();
extern void func_L01_004642F0();
extern void func_L01_00464400();
extern void func_L01_00464558();
extern void func_L01_00464910();
extern void func_L01_00465168();
extern void func_L01_00465520();
extern void func_L01_00465650();
extern void func_L01_00465878();
extern void func_L01_00465CD0();
extern void func_L01_00465F88_00462978();
extern void func_L01_00465F90();
extern void func_L01_004661F0();
extern void func_L01_00466290();
extern void func_L01_00466678();
extern void func_L01_00466B78();
extern void func_L01_00466E40();
extern void func_L01_004670C8();
extern void func_L01_004674D8();
extern void func_L01_00467608();
extern void func_L01_00467910();
extern void func_L01_00467B20();
extern void func_L01_00467DC8();
extern void func_L01_004682B8();
extern void func_L01_00468468();
extern void func_L01_00468640();
extern void func_L01_00468828();
extern void func_L01_00468B70();
extern void func_L01_00468D98();
extern void func_L01_00468F08();
extern void func_L01_00469018();
extern void func_L01_00469130();
extern void func_L01_004693D8();
extern void func_L01_00469BD0();
extern void func_L01_00469D88();
extern void func_L01_0046A430();
extern void func_L01_0046A798();
extern void func_L01_0046AA88();
extern void func_L01_0046ACD0();
extern void func_L01_0046AE98();
extern void func_L01_0046AF38();
extern void func_L01_0046AFD8();
extern void func_L01_0046B0B8();
extern void func_L01_0046B198();
extern void func_L01_0046B3A8();
extern void func_L01_0046B5F0();
extern void func_L01_0046B898();
extern void func_L01_0046BAE0();
extern void func_L01_0046BC18();
extern void func_L01_0046BCB0();
extern void func_L01_0046BF78();
extern void func_L01_0046C418();
extern void func_L01_0046C5C8();
extern void func_L01_0046C790();
extern void func_L01_0046CB28();
extern void func_L01_0046CC20();
extern void func_L01_0046CDA8();
extern void func_L01_0046CFD8();
extern void func_L01_0046D3B0();
extern void func_L01_0046D5A8();
extern void func_L01_0046D850();
extern void func_L01_0046D980();
extern void func_L01_0046DBE8();
extern void func_L01_0046DC50();
extern void func_L01_0046DF90();
extern void func_L01_0046DFD0();
extern void func_L01_0046E1B8();
extern void func_L01_0046E380();
extern void func_L01_0046E4A0();
extern void func_L01_0046E4F0();
extern void func_L01_0046E720();
extern void func_L01_0046EA10();
extern void func_L01_0046EB58();
extern void func_L01_0046EEA0();
extern void func_L01_0046F2B8();
extern void func_L01_0046F938();
extern void func_L01_0046FA88();
extern void func_L01_0046FD18();
extern void func_L01_0046FE60();
extern void func_L01_00470000();
extern void func_L01_004702E0();
extern void func_L01_00470770();
extern void func_L01_00470A28();
extern void func_L01_00470E48();
extern void func_L01_004710F8();
extern void func_L01_004711C0();
extern void func_L01_004712E0();
extern void func_L01_00471530();
extern void func_L01_00471670();
extern void func_L01_00471748();
extern void func_L01_00471A30();
extern void func_L01_00471B20();
extern void func_L01_00471D88();
extern void func_L01_00471F78();
extern void func_L01_00471FB0();
extern void func_L01_00472158();
extern void func_L01_004723B0();
extern void func_L01_00472758();
extern void func_L01_00472C98();
extern void func_L01_004730F8();
extern void func_L01_004734A8();
extern void func_L01_004736F0();
extern void func_L01_00473860();
extern void func_L01_004739D0_00462978();
extern void func_L01_00473AC8();
extern void func_L01_004741B8();
extern void func_L01_00474328();
extern void func_L01_004744D0();
extern void func_L01_004747C0();
extern void func_L01_00474968();
extern void func_L01_00474B48();
extern void func_L01_00474DE0();
extern void func_L01_00474F38();
extern void func_L01_00475278();
extern void func_L01_004756D0();
extern void func_L01_00475910();
extern void func_L01_00475DC8();
extern void func_L01_004760C8();
extern void D_L01_00474070();

/* particle_types_init: fills particle_update_table, the update routine of each particle type. */
void func_L01_00462978(void) {
    D_L01_00220E40[0x0] = func_L01_00463038;
    D_L01_00220E40[0x1] = func_L01_004632D0;
    D_L01_00220E40[0x2] = func_L01_00463538;
    D_L01_00220E40[0x3] = func_L01_004637C0_00462978;
    D_L01_00220E40[0x4] = func_L01_004638C8;
    D_L01_00220E40[0x5] = func_L01_004639C8;
    D_L01_00220E40[0x6] = func_L01_00463A70;
    D_L01_00220E40[0x7] = func_L01_00464178;
    D_L01_00220E40[0x8] = func_L01_004642F0;
    D_L01_00220E40[0x9] = func_L01_00464400;
    D_L01_00220E40[0xA] = func_L01_00464558;
    D_L01_00220E40[0xB] = func_L01_00464910;
    D_L01_00220E40[0xC] = func_L01_00465168;
    D_L01_00220E40[0xD] = func_L01_00465520;
    D_L01_00220E40[0xE] = func_L01_00465650;
    D_L01_00220E40[0xF] = func_L01_00465878;
    D_L01_00220E40[0x10] = func_L01_00465CD0;
    D_L01_00220E40[0x11] = func_L01_00465F88_00462978;
    D_L01_00220E40[0x12] = func_L01_00465F90;
    D_L01_00220E40[0x13] = func_L01_004661F0;
    D_L01_00220E40[0x14] = func_L01_00466290;
    D_L01_00220E40[0x15] = func_L01_00466678;
    D_L01_00220E40[0x16] = func_L01_00461B28;
    D_L01_00220E40[0x17] = func_L01_00466B78;
    D_L01_00220E40[0x18] = func_L01_00466E40;
    D_L01_00220E40[0x19] = func_L01_004670C8;
    D_L01_00220E40[0x1A] = func_L01_004674D8;
    D_L01_00220E40[0x1B] = func_L01_00467608;
    D_L01_00220E40[0x1C] = func_L01_00467910;
    D_L01_00220E40[0x1D] = func_L01_00467B20;
    D_L01_00220E40[0x1E] = func_L01_00467DC8;
    D_L01_00220E40[0x1F] = func_L01_004682B8;
    D_L01_00220E40[0x20] = func_L01_00468468;
    D_L01_00220E40[0x21] = func_L01_00468640;
    D_L01_00220E40[0x22] = func_L01_00468828;
    D_L01_00220E40[0x23] = func_L01_00468B70;
    D_L01_00220E40[0x24] = func_L01_00468D98;
    D_L01_00220E40[0x25] = func_L01_00468F08;
    D_L01_00220E40[0x26] = func_L01_00469018;
    D_L01_00220E40[0x27] = func_L01_00469130;
    D_L01_00220E40[0x28] = func_L01_004693D8;
    D_L01_00220E40[0x29] = func_L01_00469BD0;
    D_L01_00220E40[0x2A] = func_L01_00469D88;
    D_L01_00220E40[0x2B] = func_L01_0046A430;
    D_L01_00220E40[0x2C] = func_L01_0046A798;
    D_L01_00220E40[0x2D] = func_L01_0046AA88;
    D_L01_00220E40[0x2E] = func_L01_0046ACD0;
    D_L01_00220E40[0x2F] = func_L01_0046AE98;
    D_L01_00220E40[0x30] = func_L01_0046AF38;
    D_L01_00220E40[0x31] = func_L01_0046AFD8;
    D_L01_00220E40[0x32] = func_L01_0046B0B8;
    D_L01_00220E40[0x33] = func_L01_0046B198;
    D_L01_00220E40[0x34] = func_L01_0046B3A8;
    D_L01_00220E40[0x35] = func_L01_0046B5F0;
    D_L01_00220E40[0x36] = func_L01_0046B898;
    D_L01_00220E40[0x37] = func_L01_0046BAE0;
    D_L01_00220E40[0x38] = func_L01_0046BC18;
    D_L01_00220E40[0x39] = func_L01_0046BCB0;
    D_L01_00220E40[0x3A] = func_L01_0046BF78;
    D_L01_00220E40[0x3B] = func_L01_0046C418;
    D_L01_00220E40[0x3C] = func_L01_0046C5C8;
    D_L01_00220E40[0x3D] = func_L01_0046C790;
    D_L01_00220E40[0x3E] = func_L01_0046CB28;
    D_L01_00220E40[0x3F] = func_L01_0046CC20;
    D_L01_00220E40[0x40] = func_L01_0046CDA8;
    D_L01_00220E40[0x41] = func_L01_0046CFD8;
    D_L01_00220E40[0x42] = func_L01_0046D3B0;
    D_L01_00220E40[0x43] = func_L01_0046D5A8;
    D_L01_00220E40[0x44] = func_L01_0046D850;
    D_L01_00220E40[0x45] = func_L01_0046D980;
    D_L01_00220E40[0x46] = func_L01_0046DBE8;
    D_L01_00220E40[0x47] = func_L01_0046DC50;
    D_L01_00220E40[0x48] = func_L01_0046DF90;
    D_L01_00220E40[0x49] = func_L01_0046DFD0;
    D_L01_00220E40[0x4A] = func_L01_0046E1B8;
    D_L01_00220E40[0x4B] = func_L01_0046E380;
    D_L01_00220E40[0x4C] = func_L01_0046E4A0;
    D_L01_00220E40[0x4D] = func_L01_0046E4F0;
    D_L01_00220E40[0x4E] = func_L01_0046E720;
    D_L01_00220E40[0x4F] = func_L01_0046EA10;
    D_L01_00220E40[0x50] = func_L01_0046EB58;
    D_L01_00220E40[0x51] = func_L01_0046EEA0;
    D_L01_00220E40[0x52] = func_L01_0046F2B8;
    D_L01_00220E40[0x53] = func_L01_0046F938;
    D_L01_00220E40[0x54] = func_L01_0046FA88;
    D_L01_00220E40[0x55] = func_L01_00461C20;
    D_L01_00220E40[0x56] = func_L01_0046FE60;
    D_L01_00220E40[0x57] = func_L01_00470000;
    D_L01_00220E40[0x58] = func_L01_0046FD18;
    D_L01_00220E40[0x59] = func_L01_004702E0;
    D_L01_00220E40[0x5A] = func_L01_00470770;
    D_L01_00220E40[0x5B] = func_L01_00470A28;
    D_L01_00220E40[0x5C] = func_L01_00470E48;
    D_L01_00220E40[0x5D] = func_L01_00461C20;
    D_L01_00220E40[0x5E] = func_L01_004710F8;
    D_L01_00220E40[0x5F] = func_L01_004711C0;
    D_L01_00220E40[0x60] = func_L01_004712E0;
    D_L01_00220E40[0x61] = func_L01_00471530;
    D_L01_00220E40[0x62] = func_L01_00471670;
    D_L01_00220E40[0x63] = func_L01_00471748;
    D_L01_00220E40[0x64] = func_L01_00471A30;
    D_L01_00220E40[0x65] = func_L01_00471B20;
    D_L01_00220E40[0x66] = func_L01_00471D88;
    D_L01_00220E40[0x67] = func_L01_00471F78;
    D_L01_00220E40[0x68] = func_L01_00471FB0;
    D_L01_00220E40[0x69] = func_L01_00472158;
    D_L01_00220E40[0x6A] = func_L01_004723B0;
    D_L01_00220E40[0x6B] = func_L01_00472758;
    D_L01_00220E40[0x6C] = func_L01_00472C98;
    D_L01_00220E40[0x6D] = func_L01_004730F8;
    D_L01_00220E40[0x6E] = func_L01_004734A8;
    D_L01_00220E40[0x6F] = func_L01_004736F0;
    D_L01_00220E40[0x70] = func_L01_00473860;
    D_L01_00220E40[0x71] = func_L01_004739D0_00462978;
    D_L01_00220E40[0x72] = func_L01_00473AC8;
    D_L01_00220E40[0x73] = D_L01_00474070;
    D_L01_00220E40[0x74] = func_L01_004741B8;
    D_L01_00220E40[0x75] = func_L01_00474328;
    D_L01_00220E40[0x76] = func_L01_004744D0;
    D_L01_00220E40[0x77] = func_L01_004747C0;
    D_L01_00220E40[0x78] = func_L01_00474968;
    D_L01_00220E40[0x79] = func_L01_00474B48;
    D_L01_00220E40[0x7A] = func_L01_00474DE0;
    D_L01_00220E40[0x7B] = func_L01_00474F38;
    D_L01_00220E40[0x7C] = func_L01_00475278;
    D_L01_00220E40[0x7D] = func_L01_004756D0;
    D_L01_00220E40[0x7E] = func_L01_00475910;
    D_L01_00220E40[0x7F] = func_L01_00475DC8;
    D_L01_00220E40[0x80] = func_L01_004760C8;
}
/* localdecomp:end func_L01_00462978 */

LINKER_REMNANT("asm/levels", func_L01_00463030);

/* localdecomp:start func_L01_00463038 */
#include "vu0.h"
extern s32 D_L01_001D545C;
__asm__(".extern D_L01_001D545C, 16");
extern f32 D_L01_001E02A0_00463038;
__asm__(".extern D_L01_001E02A0_00463038, 16");
extern f32 D_L01_001E02B0_00463038;
__asm__(".extern D_L01_001E02B0_00463038, 16");
extern f32 D_L01_001E02A8_00463038;
__asm__(".extern D_L01_001E02A8_00463038, 16");
void func_L01_00463038(u8 *p) {
    extern void func_003CD250(u8 *);
    extern f32 func_L01_00451768(void *);
    u8 *vars=p+0x30;
    vu0_v4 delta;
    s32 x,y;
    f32 oldx,oldy;
    f32 floor=*(f32 *)(vars+12);
    if(D_L01_001D545C==15) {
        if(*(f32 *)(p+24)<floor) {func_003CD250(p);return;}
    } else if(*(f32 *)(p+24)<floor || *(f32 *)(p+16)<0.0f || *(f32 *)(p+20)<0.0f || *(f32 *)(p+16)>1024.0f || *(f32 *)(p+20)>1024.0f) goto kill;
    vec_add_ab(&delta, vars, &D_L01_001E02A0_00463038);
    oldx=*(f32 *)(p+32);
    oldy=*(f32 *)(p+36);
    x=(s32)oldx;
    y=(s32)oldy;
    vec_add_ab(p+32, p+32, &delta);
    vec_add_ab(p+16, p+16, &delta);
    if(*(s16 *)(p+10)!=2 && (x!=(s32)*(f32 *)(p+32) || y!=(s32)*(f32 *)(p+36))) {
        vu0_v4 first,second;
        first=*(vu0_v4 *)(p+32);
        if(func_L01_00451768(&first)<D_L01_001E02B0_00463038) floor=D_L01_001E02B0_00463038;
        else {second=*(vu0_v4 *)(p+32);floor=func_L01_00451768(&second);}
        if(*(f32 *)(p+40)<floor) {
kill:
            func_003CD250(p);
            return;
        }
    }
    *(f32 *)(vars+8)-=0.003920000046491623f;
    *(f32 *)(vars+12)=floor+D_L01_001E02A8_00463038;
    return;
}
/* localdecomp:end func_L01_00463038 */

/* localdecomp:start func_L01_00463218 */
typedef int Q_463218 __attribute__((mode(TI)));
extern u8 *D_L01_0022109C[];
extern u8 *func_L01_004618E0(s32);

void func_L01_00463218(void *a0, s32 a1, s32 a2) {
    u8 *p = func_L01_004618E0(1);
    if (p != 0) {
        ((f32 *)a0)[2] += 0.2f;
        *(Q_463218 *)(p + 0x10) = *(Q_463218 *)a0;
        *(u32 *)(p + 4) = (a1 << 24) | 0x907070;
        p[9] = 0x42;
        p[3] = 0x44;
        p[1] = 0;
        p[2] = *D_L01_0022109C[0];
        *(f32 *)(p + 0xC) = 63000.004f;
        p[8] = 0xA0;
        *(s16 *)(p + 0xA) = 0x16;
        *(s32 *)(p + 0x20) = a1;
    }
}
/* localdecomp:end func_L01_00463218 */

/* localdecomp:start func_L01_004632D0 */
extern s32 func_0038CB00(u8 *);
extern void func_003CD250(u8 *);
extern u8 *D_L01_0022109C[];

void func_L01_004632D0(u8 *self) {
    s32 alpha = *(s16 *)(self + 0xA) * *(s32 *)(self + 0x20) / 22;
    *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFFu) | (alpha << 24);
    if (func_0038CB00(self + 0xA)) {
        func_003CD250(self);
    } else {
        self[2] = D_L01_0022109C[0][(22 - *(s16 *)(self + 0xA)) * 9 / 22];
    }
}
/* localdecomp:end func_L01_004632D0 */
