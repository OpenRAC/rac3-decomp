#include "common.h"

/* localdecomp:start func_L01_004AD7A8 */
extern void func_003A62D0(s32, s32, s32);
extern void func_003A8450(void);
void func_L01_004AD7A8(s32 a0) {
    func_003A62D0(a0, 1, 1);
    func_003A62D0(a0, 2, 1);
    func_003A8450();
}
/* localdecomp:end func_L01_004AD7A8 */

LINKER_REMNANT("asm/levels", func_L01_004AD7F0);

/* localdecomp:start func_L01_004AD808 */
#include "vu0.h"

typedef int u128_004AD808 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004AD808;
typedef struct { u8 pad0[0x10]; V_004AD808 pos; } O_004AD808;

extern u128_004AD808 D_L01_002EDEB0[];
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L01_004AD808(void *a0, f32 z0) {
    O_004AD808 *o = a0;
    V_004AD808 v10;
    V_004AD808 v20;
    V_004AD808 v30;
    V_004AD808 *pv = &v10;
    u128_004AD808 *row;
    s32 i;

    for (i = 0; i < 6; i++) {
        v10.x = func_003824E0(-0.020000001f, 0.020000001f);
        v10.y = func_003824E0(-0.020000001f, 0.020000001f);
        v10.z = z0 + func_003824E0(-0.0050000004f, 0.0050000004f);
        v10.w = 0.4f;
        *(u128_004AD808 *)&v20 = *(u128_004AD808 *)&v10;
        v20.w = 0.6f;
        row = &D_L01_002EDEB0[i];
        *(u128_004AD808 *)&v30 = *row;
        func_0038D000(&v30, &v30, (u8 *)o + 0xC0);
        vec_add_ab(&v30, &v30, &o->pos);
        func_L01_00463378(&v30, pv, &v20, 0x30F0F0F0, 0x14F0F0F0, 3, 3, func_00382468(3) + 3, 0x17);
    }
}
/* localdecomp:end func_L01_004AD808 */

/* localdecomp:start func_L01_004AD9A0 */
#include "vu0.h"

typedef struct {
    u8 pad00[0xC];
    u8 count;
    u8 pad0D[0x3B];
    s32 slots[1];
} PlaybackClass;
typedef struct {
    u8 pad00[0x10];
    vu0_v4 position;
    u8 status;
    u8 pad21[3];
    PlaybackClass *classData;
    u8 pad28[0xA];
    s16 drawDistance;
    u16 flags;
    u8 pad36[2];
    unsigned long colorData;
    u8 frame, nextFrame;
    u8 pad42[2];
    f32 animTime;
    u8 pad48[0x10];
    u8 *joints, *previousJoints;
    u8 pad60, animId, opacity, mobyState;
    u8 pad64[4];
    u8 *keys;
    u8 pad6C[3];
    u8 shadowRange;
    u8 pad70[8];
    u32 color;
    u8 pad7C[0x19];
    u8 effectOpacity;
    u8 pad96[2];
    s32 updateState;
    u8 pad9C[0xE];
    s16 classId;
    u8 padAC[6];
    s16 partFlags;
    u8 padB4[8];
    u8 effectScale;
    u8 padBD[3];
    f32 matrix[12];
    vu0_v4 rotation;
} PlaybackMoby;
typedef struct {
    PlaybackMoby *object;
    u8 pad04[4];
    PlaybackMoby *extra;
    u8 pad0C[4];
    PlaybackMoby *hero;
    PlaybackMoby *companion;
    u8 pad18[8];
    s16 mode, frame;
    s16 unused24, skip;
    u8 pad28[0x18];
    s32 curveIndex, cameraStart, cameraEnd;
    f32 progress, speed, length, cameraBlend, cameraVelocity;
    u8 pad60[0xC];
    s32 fadeStart;
    u8 pad70[0x20];
    vu0_v4 startPosition, endPosition, startRotation, endRotation;
    vu0_v4 matrix[4];
} PlaybackState;
typedef struct {
    u8 pad00[0x30];
    s32 selected, frame, streamFrame, chunk;
    s16 endFrame, unused42, objectCount;
    u8 pad46[0x1E];
    u8 *keys;
    u8 pad68[0x138];
    PlaybackMoby *objects[1];
} PlaybackScene;
typedef struct { s32 at, advance; } PlaybackSkip;
typedef struct { u8 pad[0x1A4]; u32 pressed; } PlaybackPad;
typedef struct { u8 pad[0x76]; s16 mode0; u8 pad78[0x20]; s16 position; u8 pad9A[4]; s16 mode1; } PlaybackStream;
typedef struct { u8 pad[0xB0]; f32 fieldOfView; } PlaybackScreen;
typedef struct {
    u8 pad00[0x140];
    vu0_v4 position, rotation;
    f32 forward[4], right[4], up[4];
} PlaybackCamera;
typedef struct { f32 x, y, z, rot; } PlaybackPoint;
typedef struct { s32 count; u8 pad04[0xC]; PlaybackPoint points[1]; } PlaybackCurve;
typedef struct { u8 pad00[0x10]; u8 n10; u8 pad11[2]; u8 n13; u8 pad14[8]; s32 a1C[1]; } PlaybackBones;
typedef struct { u8 pad[0x70]; f32 angles[4]; } PlaybackCamRecord;

extern PlaybackState D_0016C580;
extern PlaybackScene D_L01_001E6D80;
extern PlaybackSkip D_L01_002EDF10[][4];
extern s32 D_00143950[];
extern f32 D_L01_001DF950;
extern f32 D_L01_001DF958;
extern PlaybackPad *D_001D52FC;
extern PlaybackStream D_001CCFD0;
extern s32 D_001D545C;
extern s32 D_00142C54[];
extern s32 D_00142C08[];
extern s32 D_00142BA0[];
extern u8 D_001426E0[];
extern s32 D_L01_001D9A70, D_L01_001D9A74, D_L01_001D9A78, D_L01_001D9A7C, D_L01_001D9A80;
extern s32 D_L01_001DFB54;
extern s32 D_L01_001D6674;
extern s16 D_L01_001D6706;
extern PlaybackScreen D_L01_001E7580;
extern PlaybackCamera D_L01_001E2880;
extern PlaybackMoby *D_L01_0023AC70[];
extern PlaybackMoby *D_L01_001E0E68;
extern u8 D_L01_001EA7C0[];
extern u8 *D_L01_001E0100;
extern PlaybackCurve *D_L01_0021F6C0[];
extern u8 D_L01_001FDBDA[];
extern u8 D_001A4BE0[];
extern u8 D_001439F4[];
extern f32 D_L01_001D9A50[2] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9A50, 8");
extern f32 D_L01_001D9A60[2] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9A60, 8");
extern u8 D_L01_00252880[];

extern void func_003E5520();
extern void func_003CD058(void);
extern void func_L01_004AB0E0(void);
extern void func_L01_004E20E8(void);
extern void func_003CD350(void);
extern void func_0039A690(s32);
extern void func_0038A238(s32);
extern void func_003A9050(void);
extern void func_003873C0(void);
extern void func_003C2880(void *);
extern void func_L01_004B9798(s32);
extern void func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern void func_0039EF28(void);
extern void func_L01_004BA7B8(void);
extern void func_L01_004ACBC8(s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_003A0F98(s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0012FF40(void *);
extern void func_00130088(void *, void *, f32);
extern void func_00130130(void *, void *, f32);
extern void func_0012FFE0(void *, void *, f32);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C29B0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D590(void *, void *);
extern void func_003C7C38(void *);
extern void func_L01_00447450_004AD9A0(void *);
extern void func_L01_004E2988(void *);
extern void func_L01_00512A30(void *, s32);
extern void func_003A58C0(void *, s32);
extern void func_003A7AF8();
extern void func_L01_004AC618();
extern void func_L01_004ACF48();
extern void func_L01_00404A10_004AD9A0(void *, void *);
extern void func_L01_00404808(void *, void *);
extern f32 func_0038D098(f32);
extern void func_003A4288(void);
extern void func_003D0B20(void);
extern void func_L01_0043AB98(void);
extern void func_003E55B8(void);
extern void func_L01_0045F328(s32);
extern void func_003A2750(s32);
extern void func_003A2B68(s32, s32);
extern void func_0012C908(s32);
extern void func_003A1798(void);
extern PlaybackMoby *func_003C24B0(s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_003C41A0(void *, f32, f32, f32, f32, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_0038D328(void *, void *);
extern void func_003C7DD8(void *);
extern void func_L01_004AD808(void *, f32);
extern void func_L01_00477998(void *, s32, void *, void *, s32, f32);
extern void func_L01_0043C8F8(void *, s32, void *, s32);
extern void func_00384D88(void);
extern void func_L01_004AD7A8(s32);

#define state (&D_0016C580)
#define W(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
#define scene (&D_L01_001E6D80)
#define REC(n) ((PlaybackCamRecord *)(D_L01_001E0100 + (n) * 128))

s32 func_L01_004AD9A0(void)
{
    f32 temp[16] __attribute__((aligned(16)));

    state->frame++;
    switch (state->mode) {
    case 0:
    case 3:
        func_003E5520();
        func_003CD058();
        func_L01_004AB0E0();
        func_L01_004E20E8();
        func_003CD350();
        scene->streamFrame++;
        scene->frame++;
        {
            s32 skipIndex, advance, chunkLength;
            for (skipIndex = 0; D_L01_002EDF10[scene->selected][skipIndex].at >= 0; skipIndex++) {
                if (scene->frame == (D_L01_002EDF10[scene->selected][skipIndex].at * 5 + 2) / 6) {
                    advance = (D_L01_002EDF10[scene->selected][skipIndex].advance * 5 + 2) / 6;
                    chunkLength = D_00143950[0] ? 80 : 96;
                    scene->frame += advance;
                    scene->streamFrame += advance;
                    if (scene->streamFrame >= chunkLength) {
                        scene->chunk = scene->frame / chunkLength;
                        func_0039A690(scene->chunk);
                        scene->streamFrame = scene->frame % chunkLength;
                    }
                    break;
                }
            }
        }
        D_L01_001DF950 -= 0.125f;
        if (D_L01_001DF950 < 0.0f) D_L01_001DF950 = 0.0f;
        {
            s32 limit, skip;
            limit = D_00143950[0] ? 80 : 96;
            skip = state->skip;
            if ((D_001D52FC->pressed & 0x9FF) && scene->frame >= 11 && D_L01_001DF950 == 0.0f
                && scene->frame < scene->endFrame - 25) skip = 1;
            if (skip) {
                if ((u16)((u16)D_001CCFD0.mode0 - 6) >= 2) D_001CCFD0.mode0 = 5;
                if ((u16)((u16)D_001CCFD0.mode1 - 6) >= 2) D_001CCFD0.mode1 = 5;
                if (state->mode == 0) {
                    scene->frame = scene->endFrame - 25;
                    scene->chunk = scene->frame / limit;
                    func_0039A690(scene->chunk);
                    scene->streamFrame = scene->frame % limit;
                    if (state->skip) state->skip = 0;
                    else func_0038A238(4);
                    D_L01_001DF950 = 1.0f;
                } else {
                    if (state->skip) state->skip = 0;
                    if (scene->frame < 5) state->fadeStart = -5;
                    else state->fadeStart = scene->frame - 1;
                }
            }
        }
        if (state->mode == 3) {
            s32 j;
            j = state->fadeStart;
            if (j == 0) j = scene->endFrame - 6;
            if (scene->frame >= j) {
                D_L01_001DF950 = (scene->frame - j) * 0.2f;
                if (D_L01_001DF950 > 1.0f) scene->frame = scene->endFrame;
                if (D_L01_001DF950 > 1.0f) D_L01_001DF950 = 1.0f;
            }
        }
        {
            s32 endFrame, flagA, flagB, flagC;
            endFrame = scene->endFrame;
            flagA = 0;
            if (D_001D545C == 0x13 && state->mode == 0 && (D_00142C54[0] & 0x200000))
                if (!(D_00142C54[0] & 0x400000)) flagA = 1;
            flagB = 0;
            if (D_001D545C == 5 && state->mode == 0 && (D_00142BA0[0x88 / 4] & 0x800))
                if (!(D_00142BA0[0x8C / 4] & 0x1000)) flagB = 1;
            flagC = 0;
            if (D_001D545C == 1 && state->mode == 0 && (D_00142C08[0] & 0x400))
                flagC = D_001D545C;
            if (flagA) endFrame = (D_L01_001D9A70 * 5 + 2) / 6;
            else if (flagB) endFrame = (D_L01_001D9A78 * 5 + 2) / 6;
            else if (flagC) endFrame = (D_L01_001D9A80 * 5 + 2) / 6;
            if (scene->frame >= endFrame) {
                s32 i;
                if ((u16)((u16)D_001CCFD0.mode0 - 6) >= 2) D_001CCFD0.mode0 = 5;
                if ((u16)((u16)D_001CCFD0.mode1 - 6) >= 2) D_001CCFD0.mode1 = 5;
                func_003A9050();
                D_L01_001E7580.fieldOfView = 0.62f;
                func_003873C0();
                for (i = 0; i < scene->objectCount; i++) {
                    PlaybackMoby *object = scene->objects[i];
                    if (object) {
                        object->classData->count--;
                        object->classData->slots[object->classData->count] = 0;
                        func_003C2880(object);
                        scene->objects[i] = 0;
                    }
                    if (state->extra) func_003C2880(state->extra);
                }
                state->object->flags &= 0xFFFE;
                {
                    s32 k;
                    for (k = 0; D_L01_0023AC70[k]; k++)
                        if (D_L01_0023AC70[k]->mobyState) D_L01_0023AC70[k]->mobyState = 8;
                }
                func_L01_004B9798(0);
                if (flagA) {
                    func_00392B20(D_L01_001EA7C0, 0xB6);
                    func_00392C78(D_L01_001EA7C0);
                    D_L01_001D9A74 = 1;
                    func_0038A238(6);
                    D_001426E0[0x82] |= 1;
                    func_0039EF28();
                    func_L01_004BA7B8();
                } else if (flagB) {
                    func_00392B20(D_L01_001EA7C0, 0x8C);
                    func_00392C78(D_L01_001EA7C0);
                    D_L01_001D9A7C = 1;
                    func_0038A238(6);
                    func_L01_004BA7B8();
                } else if (flagC) {
                    func_L01_004ACBC8(2);
                } else if (state->mode == 0) {
                    if (!func_003A0EC0(3, 1, 4, 0, 0)) {
                        func_0038A238(2);
                        D_L01_001DFB54 = 1;
                    }
                } else {
                    func_003A0F98(0, 0);
                }
            } else {
                u8 *key, *rotation;
                s32 last, i;
                {
                    s32 chunkLength = D_00143950[0] ? 80 : 96;
                    if (scene->streamFrame >= chunkLength) {
                        scene->chunk++;
                        func_0039A690(scene->chunk);
                    }
                }
                key = scene->keys + scene->streamFrame * 32;
                last = key[0xC];
                rotation = key + 0x10;
                D_L01_001E7580.fieldOfView = ((f32 *)rotation)[3];
                func_003873C0();
                *(vu0_q *)&D_L01_001E2880.position = *(vu0_q *)key;
                func_0038D000(&D_L01_001E2880.position, &D_L01_001E2880.position, state->matrix);
                vec_add_ba(&D_L01_001E2880.position, &D_L01_001E2880.position, &state->matrix[3]);
                func_0012FF40(temp);
                func_00130088(temp, temp, *(f32 *)(key + 0x10));
                func_00130130(temp, temp, ((f32 *)rotation)[1]);
                func_0012FFE0(temp, temp, ((f32 *)rotation)[2]);
                D_L01_001E2880.forward[0] = -temp[8]; D_L01_001E2880.right[0] = -temp[0]; D_L01_001E2880.up[0] = temp[4];
                D_L01_001E2880.forward[1] = -temp[9]; D_L01_001E2880.right[1] = -temp[1]; D_L01_001E2880.up[1] = temp[5];
                D_L01_001E2880.forward[2] = -temp[10]; D_L01_001E2880.right[2] = -temp[2]; D_L01_001E2880.up[2] = temp[6];
                func_0038D5F0(D_L01_001E2880.forward, state->matrix, D_L01_001E2880.forward);
                for (i = 0; i < scene->objectCount; i++) {
                    PlaybackMoby *object = scene->objects[i];
                    u8 *keys;
                    s32 half = scene->streamFrame >> 1;
                    object->frame = half;
                    object->nextFrame = half + 1;
                    func_003C29B0(object);
                    object->animTime = (f32)(scene->streamFrame & 1) * 0.5f;
                    if (last && (scene->streamFrame & 1)) object->animTime = 1.0f;
                    keys = object->keys;
                    func_0038CE20(temp, keys + object->frame * 16, 1.0f - object->animTime);
                    func_0038CE20(temp + 4, keys + object->nextFrame * 16, object->animTime);
                    vec_add_ba(&object->position, temp, temp + 4);
                    func_0038D000(&object->position, &object->position, state->matrix);
                    vec_add_ab(&object->position, &object->position, &state->matrix[3]);
                    func_0038D590(object->matrix, state->matrix);
                    object->animId = 255;
                    object->flags |= 0x100;
                    func_003C7C38(object);
                    if (object->classId == 0) {
                        object->shadowRange = 0;
                        if (state->mode == 0) {
                            if (scene->frame < 0x49) object->shadowRange = 24;
                        } else {
                            if (scene->frame >= 0x95) object->shadowRange = 24;
                        }
                    }
                    if (object->shadowRange) func_L01_00447450_004AD9A0(object);
                    if (object->classId == 0x259) func_L01_004E2988(object);
                    if (object->classId == 0) func_L01_00512A30(object, 0);
                    if (object->classId == 0xD54) {
                        PlaybackMoby *cast_moby;
                        s32 cast;
                        object->mobyState = 8;
                        func_003A58C0(object, 0);
                        if (!D_L01_001E0E68 || D_L01_001E0E68->classId == 0xD54)
                            func_L01_00404A10_004AD9A0(func_003A7AF8, object);
                        func_L01_00404808(func_L01_004AC618, object);
                        cast_moby = 0;
                        for (cast = 0; D_L01_0023AC70[cast]; cast++) {
                            if (D_L01_0023AC70[cast]->classId == D_L01_001D6706) {
                                cast_moby = D_L01_0023AC70[cast];
                                break;
                            }
                        }
                        if (cast_moby) {
                            if (state->mode == 0) {
                                if (scene->frame < 0x165) {
                                    s32 color = (s32)((scene->frame - 237.0f) * 1.8000001f);
                                    if (color > 255) color = 255;
                                    if (color < 0) color = 0;
                                    cast_moby->color = color | (color << 8) | (color << 16);
                                    if (scene->frame >= 0x120) {
                                        object->effectScale = (s32)((scene->frame - 287.0f) * 1.44f);
                                        object->partFlags = 0;
                                        func_L01_00404808(func_L01_004ACF48, object);
                                    }
                                    if (scene->frame >= 0x144) {
                                        D_L01_001DF958 += 0.0324f;
                                        if (D_L01_001DF958 > 1.0f) D_L01_001DF958 = 1.0f;
                                    }
                                } else {
                                    *(u32 *)((u8 *)cast_moby + 0x78) = 0xA0A0A0;
                                    D_L01_001DF958 -= 0.0324f;
                                    if (D_L01_001DF958 < 0.0f) D_L01_001DF958 = 0.0f;
                                }
                            } else {
                                if (scene->frame < 0x6C) {
                                    s32 color = ((0x6C - scene->frame) * 255) / 0x6C;
                                    cast_moby->color = color | (color << 8) | (color << 16);
                                    if (scene->frame < 0x3A) object->effectScale = ((0x3A - scene->frame) * 100) / 0x3A;
                                    object->partFlags = 0;
                                    func_L01_00404808(func_L01_004ACF48, object);
                                } else {
                                    s32 color = (s32)(func_0038D098((f32)((scene->frame & 63) - 32) * 0.09817477f) * 80.0f) + 120;
                                    cast_moby->color = color | (color << 8) | (color << 16);
                                }
                            }
                        }
                    }
                }
                func_003A4288();
                func_003D0B20();
                func_L01_0043AB98();
                func_003E55B8();
            }
        }
        break;
    case 1:
        { u8 *h = D_001A4BE0; *(s32 *)(h + 0x16B0) = 0; }
        func_003E5520();
        func_003CD058();
        func_L01_004AB0E0();
        func_L01_004E20E8();
        func_003CD350();
        if (state->frame == 0) {
            func_L01_0045F328(0);
            func_003A2750(0);
            func_003A2B68(0x138E, 0);
            while (D_001CCFD0.mode0 != 0 || D_001CCFD0.mode1 != 3 || D_001CCFD0.position >= 7000) {
                func_003A4288();
                func_0012C908(0);
            }
            func_003A1798();
            state->object->opacity = 255;
            state->object->updateState = 0;
            if (state->curveIndex >= 0) {
                u8 *global;
                state->hero = func_003C24B0(0, 0x80);
                global = D_001A4BE0;
                state->hero->drawDistance = 0x1FF;
                state->hero->opacity = 255;
                state->hero->updateState = 0;
                state->hero->flags |= 6;
                state->hero->colorData = *(unsigned long *)(*(u8 **)(global + 0x25C0) + 0x38);
                if (D_L01_001FDBDA[0] != 255 && *(s16 *)(global + 0x2884) == 0) {
                    state->companion = func_003C24B0(10, 0x80);
                    state->companion->drawDistance = 0x1FF;
                    state->companion->opacity = 255;
                    state->companion->updateState = 0;
                    state->companion->flags |= 6;
                    state->companion->colorData = *(unsigned long *)(*(u8 **)(global + 0x25C0) + 0x38);
                } else state->companion = 0;
            }
            func_L01_003EB438(0, &D_L01_001E2880.position, &D_L01_001E2880.rotation, 4, 0, 0);
            state->cameraBlend = 0;
            state->cameraVelocity = 0;
            if (state->curveIndex >= 0) {
                u8 *curve;
                f32 maximum, angle, factor;
                curve = (u8 *)D_L01_0021F6C0[state->curveIndex];
                maximum = state->cameraBlend;
                {
                    s32 pathIndex;
                    for (pathIndex = 1; pathIndex < W(curve, 0) - 1; pathIndex++) {
                        u8 *point = curve + pathIndex * 16;
                        {
                            u8 *previous = curve + (pathIndex - 1) * 16;
                            angle = func_0038D160(F(point, 0x10) - F(previous, 0x10), F(point, 0x14) - F(previous, 0x14));
                        }
                        {
                            u8 *next = curve + (pathIndex + 1) * 16;
                            factor = func_0038D160(F(next, 0x10) - F(point, 0x10), F(next, 0x14) - F(point, 0x14));
                        }
                        F(point, 0x1C) = func_0038DB00(angle, factor);
                        if (maximum < fabs_asm(F(point, 0x1C))) maximum = fabs_asm(F(point, 0x1C));
                    }
                }
                F(curve, 0x1C) = F(curve, 0x2C);
                {
                    u8 *last = curve + (W(curve, 0) - 1) * 16;
                    u8 *previous = curve + (W(curve, 0) - 2) * 16;
                    angle = func_0038D160(F(last, 0x10) - F(previous, 0x10), F(last, 0x14) - F(previous, 0x14));
                }
                {
                    u8 *last = curve + (W(curve, 0) - 1) * 16;
                    factor = func_0038D160(F(curve, 0x10) - F(last, 0x10), F(curve, 0x14) - F(last, 0x14));
                }
                angle = func_0038DB00(factor, angle);
                factor = 0.2268928f / maximum;
                {
                    u8 *last = curve + (W(curve, 0) - 1) * 16;
                    F(last, 0x1C) = angle;
                }
                {
                    s32 scaleIndex;
                    for (scaleIndex = 0; scaleIndex < W(curve, 0); scaleIndex++) F(curve + scaleIndex * 16, 0x1C) *= factor;
                }
                {
                    s32 rampIndex;
                    for (rampIndex = 0; rampIndex < 20; rampIndex++)
                        F(curve + rampIndex * 16, 0x1C) = F(curve + rampIndex * 16, 0x1C) * (rampIndex * 0.05f);
                }
                state->length = func_0038CF00(curve + 0x10, curve + 0x20);
                state->progress = 0;
                state->speed = 0;
                *(vu0_q *)&state->startPosition = *(vu0_q *)&state->object->position;
                *(vu0_q *)&state->endPosition = *(vu0_q *)(curve + 0x10);
                *(vu0_q *)&state->startRotation = *(vu0_q *)&state->object->rotation;
                state->endRotation.x = F(curve, 0x1C);
                angle = func_0038CF38(curve + 0x20, curve + 0x10);
                state->endRotation.y = func_0038D160(angle, F(curve, 0x18) - F(curve, 0x28));
                state->endRotation.z = func_0038D160(F(curve, 0x20) - F(curve, 0x10), F(curve, 0x24) - F(curve, 0x14));
            }
        }
        if (state->cameraStart >= 0 && state->cameraEnd >= 0) {
            f32 angle;
            func_003C41A0(&state->cameraBlend, 1.0f, 0.00026640002f, 0.00026640002f, 0.010000001f, &state->cameraVelocity);
            func_0038CDF8(temp, D_L01_001E0100 + state->cameraStart * 128 + 0x30, D_L01_001E0100 + state->cameraEnd * 128 + 0x30, state->cameraBlend);
            angle = func_0038DB00(REC(state->cameraEnd)->angles[0], REC(state->cameraStart)->angles[0]);
            temp[4] = angle * state->cameraBlend;
            temp[4] = func_0038DAB8(REC(state->cameraStart)->angles[0], temp[4]);
            angle = func_0038DB00(REC(state->cameraEnd)->angles[1], REC(state->cameraStart)->angles[1]);
            temp[5] = angle * state->cameraBlend;
            temp[5] = func_0038DAB8(REC(state->cameraStart)->angles[1], temp[5]);
            angle = func_0038DB00(REC(state->cameraEnd)->angles[2], REC(state->cameraStart)->angles[2]);
            temp[6] = angle * state->cameraBlend;
            temp[6] = func_0038DAB8(REC(state->cameraStart)->angles[2], temp[6]);
            func_L01_003EB350(0, temp);
            func_L01_003EB3C0(0, temp + 4);
        }
        if (state->curveIndex >= 0) {
            u8 *classData;
            PlaybackBones *bones;
            s32 *table;
            if (state->frame < 100) {
                f32 blend;
                blend = (1.0f - func_0038D098(state->frame * 0.041887902f)) * 0.5f;
                if (state->frame >= 75) blend = 1.0f;
                func_0038CDF8(&state->object->position, &state->startPosition, &state->endPosition, blend);
                state->object->rotation.x = state->endRotation.x * blend;
                state->object->rotation.y = func_0038DAB8(state->startRotation.y, func_0038DB00(state->endRotation.y, state->startRotation.y) * blend);
                state->object->rotation.z = func_0038DAB8(state->startRotation.z, func_0038DB00(state->endRotation.z, state->startRotation.z) * blend);
                func_0038D328(temp, &state->object->rotation);
                func_0038D590(state->object->matrix, temp);
                func_003C7DD8(state->object);
                if (D_L01_001DF950 > 0.0f) {
                    D_L01_001DF950 -= 0.125f;
                    if (D_L01_001DF950 < 0.0f) D_L01_001DF950 = 0.0f;
                }
                state->object->effectOpacity = (u16)state->frame >> 2;
                if (blend < 1.0f) func_L01_004AD808(state->object, -0.075f);
            } else {
                PlaybackCurve *curve;
                f32 step;
                curve = D_L01_0021F6C0[state->curveIndex];
                state->speed += 0.8f;
                if (state->speed > 100.0f) state->speed = 100.0f;
                if ((D_001D52FC->pressed & 0x50) && D_L01_001DF950 < 0.1f) D_L01_001DF950 = 0.1f;
                step = state->speed * 0.020000001f / state->length;
                if ((f32)curve->count - step * 12.0f < state->progress && D_L01_001DF950 < 0.1f) D_L01_001DF950 = 0.1f;
                if (D_L01_001DF950 > 0.0f) {
                    D_L01_001DF950 += 0.1f;
                    if (D_L01_001DF950 > 1.0f) D_L01_001DF950 = 1.0f;
                }
                if (state->object->effectOpacity < 200) state->object->effectOpacity += 6;
                state->progress += step;
                if (state->progress > (f32)(curve->count - 1) || D_L01_001DF950 >= 1.0f) {
                    { u8 *h = D_001A4BE0; *(s32 *)(h + 0x16B0) = D_001439F4[0]; }
                    func_0038A238(2);
                    D_L01_001D6674 = 1;
                } else {
                    func_L01_00477998(curve, 1, &state->object->position, &state->object->rotation, 0, state->progress);
                    state->object->rotation.x = state->object->rotation.w;
                    func_0038D328(temp, &state->object->rotation);
                    func_0038D590(state->object->matrix, temp);
                    func_003C7DD8(state->object);
                }
            }
            *(vu0_q *)&state->hero->rotation = *(vu0_q *)&state->object->rotation;
            func_0038D000(&state->hero->position, D_L01_001D9A50, state->object->matrix);
            vec_add_ab(&state->hero->position, &state->hero->position, &state->object->position);
            func_003C7C38(state->hero);
            classData = (u8 *)state->hero->classData;
            bones = *(PlaybackBones **)(classData + 0x48);
            table = &bones->a1C[bones->n10];
            func_L01_0043C8F8(table + bones->n13, bones->a1C[0], D_L01_00252880, classData[8]);
            state->hero->joints = D_L01_00252880;
            state->hero->previousJoints = D_L01_00252880;
            if (state->companion) {
                *(vu0_q *)&state->companion->rotation = *(vu0_q *)&state->object->rotation;
                func_0038D000(&state->companion->position, D_L01_001D9A60, state->object->matrix);
                vec_add_ab(&state->companion->position, &state->companion->position, &state->object->position);
                func_003C7C38(state->companion);
            }
        } else {
            D_L01_001DF950 = 1.0f;
            { u8 *h = D_001A4BE0; *(s32 *)(h + 0x16B0) = D_001439F4[0]; }
            D_L01_001D6674 = 1;
        }
        func_003A58C0(state->object, 0);
        func_L01_00404A10_004AD9A0(func_L01_004AD7A8, state->object);
        func_00384D88();
        func_003A4288();
        func_003D0B20();
        func_L01_0043AB98();
        func_003E55B8();
        break;
    }
    return 0;
}
#undef state
#undef scene
#undef REC
#undef W
#undef F
/* localdecomp:end func_L01_004AD9A0 */

/* localdecomp:start func_L01_004AF178 */
extern s16 D_0016C5A0[];
extern s32 D_L01_001DF944;
extern void func_L01_00403BB8(void);
extern void func_00388AF8(s32);

void func_L01_004AF178(void) {
    switch (D_0016C5A0[0]) {
    case 0:
    case 3:
        func_L01_00403BB8();
        break;
    case 1:
        D_L01_001DF944 = 127;
        func_00388AF8(0);
        break;
    }
}
/* localdecomp:end func_L01_004AF178 */

LINKER_REMNANT("asm/levels", func_L01_004AF1E0);
