/* NTSC-U draft (Codex wave 3): C of func_L39_0066E440, the NTSC-U twin of func_L39_00670D90, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 284 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_0066E440", whose code is not the PAL one).
 * Worker's note: 284 diff; best valid log w148/func_L39_0066E440.10.log; corrected inherited final load to returned player+0x2524 (.01 345 diff has wrong global and is ineligible); small table/count externs and independent team locals improve valid 358 to 284; copy/loop ...
 */
#include "common.h"
/* localdecomp:start func_L39_0066E440 */
typedef struct { u8 bytes[0x120]; } Copy133;
typedef struct { u8 bytes[0x20]; } Player133;
typedef struct { s32 players[8]; f32 a[8],b[8]; u8 gap[0x44]; } Team133;
typedef struct { s16 kills, deaths; } Score133;
typedef struct { u16 kills, deaths; } UScore133;
typedef struct {
    Player133 players[8];
    s32 active[8];
    s32 teams[8];
    Score133 scores[8];
    u8 a[8], b[8], c[8], d[8];
    f32 values[8];
    f32 limits[2];
    s32 winner;
    s32 mode;
    u8 pad1b0[8];
    s16 initial[8];
    Copy133 copy;
    Team133 groups[8];
    s32 f808, f80c, f810, elapsed, state, f81c, f820, f824, f828;
} Result133;
extern Result133 D_L39_001FD968;
extern Copy133 D_L39_001FDB30;
typedef struct { s32 count; u8 pad[0xA0]; } Count133;
extern s32 D_L39_001FDCDC[1];
__asm__(".extern D_L39_001FDCDC, 164");
typedef struct {
 s32 time, start, status; u8 padc[4]; s32 winner; u8 pad14[4];
 UScore133 scores[8]; u8 a[8], b[8], c[8], d[8]; f32 values[8]; Copy133 copy;
 u16 initial[8]; u8 pad1a8[0x1ec-0x1a8]; s32 state, valid; u8 pad1f4[12];
 s32 f200,f204,f208; u8 *settings; u8 *game;
} Source133;
extern Source133 D_L39_00352A40;
typedef struct {u8 bytes[16];} NetPlayer133;
typedef struct { NetPlayer133 players[8]; u8 pad80[0x50]; s16 teams[8], ids[8]; u8 padf0[0x20]; f32 a[8],b[8]; u8 pad150[0x30]; s32 mode, kind; u8 pad188[0x15]; s8 teamMode; } Net133;
extern Net133 *D_L39_002417C0;
extern u8 *D_001D5F30_sda;
__asm__(".extern D_001D5F30_sda, 4");
extern u8 *D_L39_0024CF20[1];
__asm__(".extern D_L39_0024CF20, 32");
typedef struct { u8 pad[0x128]; s32 time; } Time133;
extern Time133 D_001A5E50;
extern void func_L39_0066D5B8(void);
extern void func_L39_0066FAB0(void);
extern void *func_0011D534(void *, s32, s32);
extern char *func_001206F4(void *, void *);
extern void func_L01_003F0020(s32);
extern u8 *func_L39_006197C0(s32);
extern void func_L01_00402768(void *, s32);
void func_L39_0066E440(s32 state) {
    s32 i, j;
    s32 best, bestscore, bestdeaths, tied, score, deaths;
    s32 index;
    u8 *p;
    D_L39_00352A40.status=2;
    D_L39_00352A40.valid=1;
    D_L39_00352A40.state=state;
    func_L39_0066FAB0();
    func_0011D534(&D_L39_001FD968,0,0x82C);
    D_L39_001FD968.f80c=D_L39_002417C0->mode;
    D_L39_001FD968.f808=D_L39_002417C0->kind;
    D_L39_001FD968.f828=D_L39_002417C0->teamMode;
    D_L39_001FD968.state=state;
    { u8 *settings=D_L39_00352A40.settings;
    if (*(s32 *)(settings+0x88)==0) {
        D_L39_001FD968.limits[0]=*(f32 *)(settings+0x108);
        D_L39_001FD968.limits[1]=*(f32 *)(settings+0x10C);
    } else {
        D_L39_001FD968.limits[1]=*(f32 *)(settings+0x108);
        D_L39_001FD968.limits[0]=*(f32 *)(settings+0x10C);
    }
    }
    if (D_L39_00352A40.game) D_L39_001FD968.mode=*(s8 *)(D_001D5F30_sda+0x198);
    D_L39_001FDB30=D_L39_00352A40.copy;
    D_L39_001FD968.f81c=D_L39_00352A40.f200;
    D_L39_001FD968.f820=D_L39_00352A40.f204;
    D_L39_001FD968.f824=D_L39_00352A40.f208;
    {
    s32 player_index;
    for (player_index=0;player_index<8;player_index++) {
        if (D_L39_002417C0 && D_L39_002417C0->players[player_index].bytes[0]) func_001206F4(&D_L39_001FD968.players[player_index],&D_L39_002417C0->players[player_index]);
        else D_L39_001FD968.players[player_index].bytes[0]=0;
        D_L39_001FD968.active[player_index]=0;
        p=D_L39_0024CF20[player_index];
        if (p) {
            if (p[0x1A14]) {
                D_L39_001FD968.active[player_index]=1;
                func_L01_003F0020(*(s32 *)(p+0x2534));
            }
            D_L39_001FD968.teams[player_index]=*(s32 *)(D_L39_0024CF20[player_index]+0x2548);
            index=*(s32 *)(D_L39_0024CF20[player_index]+0x2548);
            j=(*(s32 *)((u8 *)D_L39_001FDCDC + index * 0xA4));
            D_L39_001FD968.groups[index].a[j]=D_L39_002417C0->a[player_index];
            index=*(s32 *)(D_L39_0024CF20[player_index]+0x2548);
            D_L39_001FD968.groups[index].b[j]=D_L39_002417C0->b[player_index];
            index=*(s32 *)(D_L39_0024CF20[player_index]+0x2548);
            D_L39_001FD968.groups[index].players[j]=player_index;
            index=*(s32 *)(D_L39_0024CF20[player_index]+0x2548);
            ((*(s32 *)((u8 *)D_L39_001FDCDC + index * 0xA4)))++;
        }
        D_L39_001FD968.scores[player_index].kills=D_L39_00352A40.scores[player_index].kills;
        D_L39_001FD968.scores[player_index].deaths=D_L39_00352A40.scores[player_index].deaths;
        D_L39_001FD968.a[player_index]=D_L39_00352A40.a[player_index];
        D_L39_001FD968.b[player_index]=D_L39_00352A40.b[player_index];
        D_L39_001FD968.values[player_index]=D_L39_00352A40.values[player_index];
        D_L39_001FD968.c[player_index]=D_L39_00352A40.c[player_index];
        D_L39_001FD968.d[player_index]=D_L39_00352A40.d[player_index];
        D_L39_001FD968.initial[player_index]=D_L39_00352A40.initial[player_index];
    }
    }
    D_L39_001FD968.elapsed=D_001A5E50.time-D_L39_00352A40.start;
    if (D_L39_00352A40.time!=-1) {
        if (D_L39_001FD968.elapsed>D_L39_00352A40.time) D_L39_001FD968.elapsed=D_L39_00352A40.time;
    }
    if (state<5) {
        if (state>=2) D_L39_001FD968.winner=D_L39_00352A40.winner;
        else if (state==1) goto choose;
    } else if (state==5) {
choose:
        if (D_L39_001FD968.f80c==2) {
            if (D_L39_002417C0->teamMode) {
                s32 team_i, team_j, team_best, team_bestscore, team_bestdeaths, team_tied, team_score, team_deaths;
                team_best=-1; team_bestscore=-1; team_bestdeaths=-1; team_tied=0;
                for (team_i=0;team_i<8;team_i++) {
                    team_score=0; team_deaths=0;
                    for (team_j=0;team_j<8;team_j++) {
                        if (D_L39_002417C0->ids[team_j]!=-1 && D_L39_002417C0->teams[team_j]==team_i) {
                            team_score+=D_L39_001FD968.scores[team_j].kills-D_L39_001FD968.initial[team_j];
                            team_deaths+=D_L39_001FD968.scores[team_j].deaths;
                        }
                    }
                    if (team_score>team_bestscore || (team_score==team_bestscore && team_deaths<team_bestdeaths)) {
                        team_bestscore=team_score; team_bestdeaths=team_deaths; team_best=team_i; team_tied=0;
                    } else if (team_score==team_bestscore && team_deaths==team_bestdeaths) team_tied=1;
                }
                if (!team_tied) D_L39_001FD968.winner=team_best;
                else D_L39_001FD968.winner=-1;
            } else {
                best=-1; bestscore=-1; tied=0;
                for (i=0;i<8;i++) {
                    if (D_L39_002417C0->ids[i]!=-1) {
                        score=D_L39_001FD968.scores[i].kills-D_L39_001FD968.initial[i];
                        if (score>bestscore) {bestscore=score;best=i;tied=0;}
                        else if (score==bestscore) {
                            if (D_L39_001FD968.scores[i].deaths<D_L39_001FD968.scores[best].deaths) {bestscore=score;best=i;tied=0;}
                            else if (D_L39_001FD968.scores[i].deaths==D_L39_001FD968.scores[best].deaths) tied=1;
                        }
                    }
                }
                if (!tied) D_L39_001FD968.winner=D_L39_001FD968.teams[best];
                else D_L39_001FD968.winner=-1;
            }
        } else if (D_L39_001FD968.f80c==1) {
            u8 *game=D_L39_00352A40.game;
            i=*(s32 *)(game+0xC); j=*(s32 *)(game+8);
            if (i<j) D_L39_001FD968.winner=0;
            else if (j<i) D_L39_001FD968.winner=1;
            else D_L39_001FD968.winner=-1;
        } else if (D_L39_001FD968.f80c==0) D_L39_001FD968.winner=-1;
    }
    p = func_L39_006197C0(0);
    func_L01_00402768(func_L39_0066D5B8,*(s32 *)(p + 0x2524));
}
/* localdecomp:end func_L39_0066E440 */
