/* NTSC-U draft (Codex wave 3): C of func_L39_006DC008, the NTSC-U twin of func_L39_006DEB68, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 74 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_006DC008", whose code is not the PAL one).
 * Worker's note: 74 diff with in-memory divs row; float/integer allocation and initial-load scheduling persist; three new initialization order/zero-local variants compile to identical bytes; best log w120/func_L39_006DC008.01.log; NEEDS divs row 'func_L39_006DC008 2 2 2 2 2 2'
 */
#include "common.h"
/* localdecomp:start func_L39_006DC008 */
typedef struct { short a,b; } Pair_DC008;
typedef struct {
 u8 pad[0x120]; int id[8]; Pair_DC008 values[8];
 u8 rank[16]; u8 count[8]; u8 extra[8]; float score[8];
 u8 pad1a0[8]; int selected; int maxCount;
 u8 pad1b0[0x80C-0x1B0]; int mode;
} Menu_DC008;
typedef struct {
 float w0[3],w1[3],w2[3],w3[3],w4[3],w5[3],w6[3];
 float maxA[3],maxB[3],maxRank[3],maxScore[3];
 float maxExtra; u8 pad88[0xD8-0x88]; float scale;
} Weights_DC008;
extern Menu_DC008 D_L39_001FD968[];
extern Weights_DC008 D_001A6AD0[];
extern int func_00197640(int);
float func_L39_006DC008(int player) {
 int mode=func_00197640(D_L39_001FD968->mode);
 float a=D_L39_001FD968->values[player].a;
 float b=D_L39_001FD968->values[player].b;
 float rank=D_L39_001FD968->rank[player];
 float count=D_L39_001FD968->count[player];
 float extra=D_L39_001FD968->extra[player];
 float score=D_L39_001FD968->score[player];
 float selected=0.0f;
 if(D_001A6AD0->maxA[mode]<a)a=D_001A6AD0->maxA[mode];
 if(a<0.0f)a=0.0f;
 if(D_001A6AD0->maxB[mode]<b)b=D_001A6AD0->maxB[mode];
 if(b<0.0f)b=0.0f;
 if(D_001A6AD0->maxScore[mode]<score)score=D_001A6AD0->maxScore[mode];
 if(score<0.0f)score=0.0f;
 if(D_001A6AD0->maxRank[mode]<rank)rank=D_001A6AD0->maxRank[mode];
 if(rank<0.0f)rank=0.0f;
 if(D_L39_001FD968->maxCount<count)count=D_L39_001FD968->maxCount;
 if(count<0.0f)count=0.0f;
 if(D_001A6AD0->maxExtra<extra)extra=D_001A6AD0->maxExtra;
 if(extra<0.0f)extra=0.0f;
 if(D_L39_001FD968->selected==D_L39_001FD968->id[player])selected=1.0f;
 score/=D_001A6AD0->maxScore[mode];
 rank/=D_001A6AD0->maxRank[mode];
 a/=D_001A6AD0->maxA[mode];
 b/=D_001A6AD0->maxB[mode];
 if(D_L39_001FD968->maxCount>0)count/=D_L39_001FD968->maxCount;
 extra/=D_001A6AD0->maxExtra;
 return D_001A6AD0->scale*(D_001A6AD0->w0[mode]*selected+D_001A6AD0->w1[mode]*a+
 D_001A6AD0->w2[mode]*b+D_001A6AD0->w3[mode]*score+D_001A6AD0->w4[mode]*rank+
 D_001A6AD0->w5[mode]*count+D_001A6AD0->w6[mode]*extra);
}
/* localdecomp:end func_L39_006DC008 */
