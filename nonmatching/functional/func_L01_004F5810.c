/* functional: medium. 107 diff words (movn lowering, allocation); Camera_004F5730 fields used instead of vu0_v4 array; D_L01_001DBCFC (gp-relative sdata) declared plainly, no asm */
#include "vu0.h"
typedef struct {
    u8 p0[0x184]; f32 f184;
    u8 p188[0x1B8-0x188]; s32 timer;
    u8 p1BC[0x298-0x1BC]; f32 f298; f32 f29C; f32 f2A0; u8 b2A4;
    u8 p2A5[0xBE4-0x2A5]; f32 pitch, yaw;
    u8 pBEC[0x1200-0xBEC]; u8 *target;
    u8 p1204[0x121A-0x1204]; u8 active;
    u8 p121B[0x1228-0x121B]; s32 mode;
    u8 p122C[0x16B0-0x122C]; s32 camera_mode;
    u8 p16B4[0x1CE0-0x16B4]; u8 sound[0x100];
    u8 p1DE0[0x25C0-0x1DE0]; u8 *moby; s32 state;
} Hero_004F5810;
extern s32 D_L01_001DBCFC;
void func_L01_004F5810(void)
{
    extern s32 func_L01_004F5730(void);
    extern s32 func_L01_004EDFA8(void *);
    extern s32 func_L01_004F4E70(s32, s32);
    extern s32 func_L01_00513EF0(void);
    extern void func_L01_00511178(void *, void *, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_003C48A8(void *, void *);
    extern void func_L01_0044E318(void *, void *);
    extern void func_L01_0044E340(void *, s32, s32, f32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern f32 func_0038DAB8(f32, f32);
    vu0_v4 rotation, matrix[3], camera[3];
    long first_person;
    u8 *moby;
    u8 *vars;
    if(((Hero_004F5810 *)&D_001A4BE0)->active) return;
    D_L01_001DBCFC=0;
    first_person=1;
    if(((Hero_004F5810 *)&D_001A4BE0)->camera_mode!=2) first_person=0;
    if(((Hero_004F5810 *)&D_001A4BE0)->state==1 || ((Hero_004F5810 *)&D_001A4BE0)->state==29)
        { first_person=1; if(((Hero_004F5810 *)&D_001A4BE0)->timer<18) first_person=0; }
    if(first_person && !func_L01_004F5730()) {
        ((Hero_004F5810 *)&D_001A4BE0)->pitch=D_L01_001E2A40.yaw;
        ((Hero_004F5810 *)&D_001A4BE0)->yaw=func_0038DAB8(-D_L01_001E2A40.pitch,0.122173049f);
    }
    moby=((Hero_004F5810 *)&D_001A4BE0)->target;
    if(func_L01_004EDFA8(moby)) {
        ((Hero_004F5810 *)&D_001A4BE0)->active=1;
        if(first_person && ((Hero_004F5810 *)&D_001A4BE0)->mode!=127)
            func_L01_004F4E70(17,0);
        vars=*(u8 **)(moby+0x68);
        moby[0x20]=10;
        if(func_L01_00513EF0()!=2) {
                    if(((Hero_004F5810 *)&D_001A4BE0)->f298<1.2f && ((Hero_004F5810 *)&D_001A4BE0)->f2A0>0.663225114f && ((Hero_004F5810 *)&D_001A4BE0)->b2A4==0)
                *(s16 *)(vars+0x76)=1;
        }
        qzero(vars+0x40);
        if(!first_person)
            func_L01_00511178(vars+0x40,vars+0x40,1.0f);
        else
            func_00382760(vars+0x40,1.0f,((Hero_004F5810 *)&D_001A4BE0)->pitch,((Hero_004F5810 *)&D_001A4BE0)->yaw);
        qzero(&rotation);
        func_0038D308(matrix,&rotation);
        if(first_person) {
            rotation.x=D_L01_001E2A40.pad10;
            rotation.y=D_L01_001E2A40.pitch;
            rotation.z=D_L01_001E2A40.yaw;
            func_0038D308(camera,&rotation);
            func_0038D5F0(matrix,camera,matrix);
        } else {
            func_0038D5F0(matrix,((Hero_004F5810 *)&D_001A4BE0)->moby+0xC0,matrix);
        }
        func_003C48A8(matrix,moby+0xF0);
        *(s32 *)(vars+0x64)=0;
        *(f32 *)(vars+0x60)=0.460000038f;
        if(((Hero_004F5810 *)&D_001A4BE0)->f184<0.400000036f) {
            u8 *sound=((Hero_004F5810 *)&D_001A4BE0)->sound;
            func_L01_0044E318(moby,sound);
            func_L01_0044E340(sound,48,3,0.0f);
            func_L01_0044E340(sound,23,5,0.0f);
        }
        func_003C3A10(moby,6,0,4);
    }
}
