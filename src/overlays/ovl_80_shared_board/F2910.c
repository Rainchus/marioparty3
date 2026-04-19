#include "common.h"
#include "ovl_80.h"

extern u32 D_800D2094_D2C94;
extern u32 D_80100EE8_114B08_shared_board;
typedef struct ItemRect {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} ItemRect;

typedef struct DefinitelyNotItemRect {
    s8 x[100500];
} DefinitelyNotItemRect;

typedef struct ItemRectTable {
    ItemRect *rects[6];
} ItemRectTable; //sizeof 0x18

typedef struct DefinitelyNotItemRectTable {
    DefinitelyNotItemRect* notRects[6];
} DefinitelyNotItemRectTable; //sizeof 0x18

typedef struct Sp18Struct {
    ItemRectTable rectTable;
    DefinitelyNotItemRectTable notRectTable1;
    DefinitelyNotItemRectTable notRectTable2;
} Sp18Struct;

typedef struct ItemSlotEntry {
/* 0x00 */ s16 obj;
/* 0x02 */ s16 x;
/* 0x04 */ s16 y;
/* 0x06 */ s16 w;
/* 0x08 */ s16 h;
} ItemSlotEntry; //sizeof 0xA

extern ItemRectTable const D_801020B0_115CD0_shared_board;
extern DefinitelyNotItemRectTable const D_801020C8_115CE8_shared_board;
extern DefinitelyNotItemRectTable const D_801020E0_115D00_shared_board;
extern ItemSlotEntry D_80102BD0_1167F0_shared_board[];
extern s8 D_80102C08_116828_shared_board[];
extern s8 D_80102C0D_11682D_shared_board;
extern u8 D_80100E18_114A38_shared_board[];
extern u8 D_80100EEC_114B0C_shared_board[];
extern u8 D_80100EF4_114B14_shared_board[];
extern u8 D_80100E20_114A40_shared_board[]; /* normal mode: recent minigame avoid count per category */
extern u8 D_80100E28_114A48_shared_board[]; /* hard mode: recent minigame avoid count per category */
extern u8 D_80100E9B_114ABB_shared_board[];
extern u8 D_80100E30_114A50_shared_board[][3];
extern u8 D_80100DA0_shared_board[];
extern u8 D_80100DC0_shared_board[];
extern u8 D_80100DD4_shared_board[];
extern u8 D_80100DF4_shared_board[];
extern u8 D_80100DE8_shared_board[];
extern u8 D_80100E04_shared_board[];
extern u8 D_80100DB4_shared_board[];
extern u8 D_80100DCC_shared_board[];
extern u8 D_80100DE0_shared_board[];
extern u8 D_80100DFC_shared_board[];
extern u8 D_80100DF0_shared_board[];
extern u8 D_80100E10_shared_board[];

extern ItemRect D_80100E44_shared_board;
extern ItemRect D_80100E5C_shared_board;

//this is odd, wrong?
typedef struct {
    u8 unk0[8];
    s8 recentMinigames[6][10]; /* recent minigames per player, up to 2 */
} UnkData_CD0A0;

extern UnkData_CD0A0 D_800CC4A0_CD0A0;
extern omObjData* D_80102C04_116824_shared_board;
extern s16 D_80102C0E_11682E_shared_board;

void func_800DED3C_F295C_shared_board(omObjData*);
s32 func_800F52C4_108EE4_shared_board(void);
void func_8005D2D4_5DED4(s16);
void func_800DF9EC_F360C_shared_board(void);

void func_800DECF0_F2910_shared_board(void) {
    if (D_800D2094_D2C94 >= (D_80100EE8_114B08_shared_board + 4)) {
        HuAudFXPlay(0x104);
        D_80100EE8_114B08_shared_board = D_800D2094_D2C94;
    }
}

typedef struct Unk800CC3DC {
    char unk_00[4];
    s8 unk_04[8]; //unknown size
} Unk800CC3DC;

extern Unk800CC3DC D_800CC3DC_CCFDC;
extern void func_800DED3C_F295C_shared_board(omObjData*);
s32 func_800F52C4_108EE4_shared_board(void);
void GWMgNoSet(s8);                                    /* extern */
void func_8005BA90_5C690(s16, s16, s16);               /* extern */
void func_8005BB18_5C718(s16, f32, f32);               /* extern */
void func_8005C154_5CD54(s16, s32, s32, s32);                /* extern */
void func_8005D2D4_5DED4(s16);                         /* extern */
void func_800DECF0_F2910_shared_board(void);               /* extern */
void func_800DF8B4_F34D4_shared_board(void);               /* extern */
void func_800DFAD4_F36F4_shared_board(void);               /* extern */
void func_800E5B90_F97B0_shared_board(void);               /* extern */

extern u8 D_80100E18_114A38_shared_board[];
extern u8 D_80100E20_114A40_shared_board[];
extern u8 D_80100E28_114A48_shared_board[];
extern u8 D_80100E84_114AA4_shared_board[];
extern u8 D_80100E8C_114AAC_shared_board[];
extern s8 D_80100E94_114AB4_shared_board[][2];
extern u16 D_80102BD4_1167F4_shared_board;
extern s16 D_80102C12_116832_shared_board;

void func_800DED3C_F295C_shared_board(omObjData* arg0) {
    ItemSlotEntry* entry = NULL;
    s32 i;
    s16 new_var;
    
    switch (arg0->work[0]) {
    case 3:
        break;
    case 0:
        if (arg0->work[1] == 0) {
            arg0->scale.y += 0.1f;
            if (arg0->scale.y > 1.0f) {
                arg0->scale.y = 1.0f;
            }
            for (i = 0; i < D_80100E18_114A38_shared_board[D_80102C0D_11682D_shared_board]; i++) {
                new_var = 0xE0;
                entry = &D_80102BD0_1167F0_shared_board[i];
                func_8005BA90_5C690(entry->obj, (entry->x + (entry->w / 2)), (entry->y + ((entry->h / 2) - new_var)));
                func_8005BB18_5C718(entry->obj, 0.0f, arg0->scale.y);
            }
   
            new_var = 0xE0;
            func_80054904_55504(D_80102C0E_11682E_shared_board, 0, 0xA0, (D_80102BD4_1167F4_shared_board + (D_80100E84_114AA4_shared_board[D_80102C0D_11682D_shared_board] - new_var)));
            
            
            HuSprScaleSet(D_80102C0E_11682E_shared_board, 0, HuMathSin(arg0->scale.x), arg0->scale.y);
            if (arg0->scale.y >= 1.0f) {
                arg0->work[0] = 4;
                arg0->work[1] = 5;
            }
        } else {
            arg0->work[1] -= 1;
        }
        break;
    case 4:
        if (arg0->work[1] != 0) {
            arg0->work[1] -= 1;
            break;
        }
        
        arg0->scale.x += 10.0f;
        if (arg0->scale.x > 90.0f) {
            arg0->scale.x = 90.0f;
        }

        for (i = 0; i < D_80100E18_114A38_shared_board[D_80102C0D_11682D_shared_board]; i++) {
            new_var = 0xE0;
            entry = &D_80102BD0_1167F0_shared_board[i];
            func_8005BA90_5C690(entry->obj, (entry->x + (entry->w / 2)), (entry->y + ((entry->h / 2) - new_var)));
            func_8005BB18_5C718(entry->obj, HuMathSin(arg0->scale.x), arg0->scale.y);
        }
        
        new_var = 0xE0;    
        func_80054904_55504(D_80102C0E_11682E_shared_board, 0, 0xA0,
            (D_80102BD4_1167F4_shared_board + (D_80100E84_114AA4_shared_board[D_80102C0D_11682D_shared_board] - new_var)));
        
        
        HuSprScaleSet(D_80102C0E_11682E_shared_board, 0, HuMathSin(arg0->scale.x), arg0->scale.y);
        
        if (arg0->scale.x >= 90.0f) {
            func_800DECF0_F2910_shared_board();
            arg0->work[0] = 1;
            arg0->scale.x = 1.0f;
            arg0->scale.z = -1.0f;
            arg0->scale.y = 0.0f;
            arg0->work[1] = 0;
            arg0->work[2] = MBRand((f32) D_80100E18_114A38_shared_board[D_80102C0D_11682D_shared_board]);
            arg0->work[3] = 0;
            func_800DFAD4_F36F4_shared_board();
        }
        break;
    case 1:
        arg0->scale.z += arg0->scale.x;
        
        if (arg0->scale.z >= 1.0f) {
            if ((arg0->work[3] != 0) && (arg0->scale.x <= 0.08f)) {
                arg0->work[3]--;
            }
            arg0->scale.z -= 1.0f;
            if (arg0->scale.y == 0.0f) {
                arg0->work[1]++;
                arg0->work[1] = arg0->work[1] % D_80100E18_114A38_shared_board[D_80102C0D_11682D_shared_board];
            } else {
                arg0->work[1]--;
                if (arg0->work[1] >= 0x80U) {
                    arg0->work[1] = D_80100E18_114A38_shared_board[D_80102C0D_11682D_shared_board] - 1;
                }
            }
            func_800DECF0_F2910_shared_board();
        }
        
        for (i = 0; i < D_80100E18_114A38_shared_board[D_80102C0D_11682D_shared_board]; i++) {
            entry = &D_80102BD0_1167F0_shared_board[i];
            if (i == arg0->work[1]) {
                func_8005FBF8_607F8(entry->obj, 0, 0xC8, 0);
                func_8005BEE0_5CAE0(entry->obj, 0x100);
                func_8005BE30_5CA30(entry->obj, 0x2328);
            } else {
                func_8005FBF8_607F8(entry->obj, 0x40, 0x40, 0x80);
                func_8005BEE0_5CAE0(entry->obj, 0);
                func_8005BE30_5CA30(entry->obj, 0x2710);
            }
        }
        
        if ((arg0->work[1] == arg0->work[2]) || (arg0->scale.x < 1.0f)) {
            arg0->scale.x = (f32) ((f64) arg0->scale.x - 0.02);
        }
        
        if (arg0->scale.x <= 0.08f) {
            arg0->scale.x = 0.08f;
            if ((arg0->work[1] == arg0->work[2]) && (arg0->work[3] == 0) && ((arg0->scale.z + 0.08f) >= 1.0f)) {
                if ((rand8() & 0xF) || (arg0->scale.y == 1.0f) || (arg0->work[1] == 0)) {
                    if ((GwSystem.show_minigame_explanations == 0) || (GwSystem.current_board_index == 6)) {
                        HuAudFXPlay(0x105);
                    } else {
                        HuAudFXPlay(0x112);
                    }
                    
                    arg0->work[0] = 2;
                    arg0->work[3] = 0x3C;
                    func_8005D2D4_5DED4(entry->obj);
                    func_8005D294_5DE94(D_80102BD0_1167F0_shared_board[arg0->work[1]].obj);
                    func_8005B43C_5C03C(D_80102BD0_1167F0_shared_board[arg0->work[1]].obj,
                        D_80102C08_116828_shared_board[arg0->work[1]] + 0x46FF, -2, 4);
                    func_8005C02C_5CC2C(D_80102BD0_1167F0_shared_board[arg0->work[1]].obj, 1);
                    func_8005C154_5CD54(D_80102BD0_1167F0_shared_board[arg0->work[1]].obj, 0xA0, 0xA0, 0xA0);
                    func_8005FBF8_607F8(D_80102BD0_1167F0_shared_board[arg0->work[1]].obj, 0xFE, 0xFF, 0xD0);
                    func_8005BDFC_5C9FC(D_80102BD0_1167F0_shared_board[arg0->work[1]].obj, 0);
                } else {
                    arg0->scale.y = 1.0f;
                    arg0->work[2]--;
                    if (arg0->work[2] >= 128) {
                        arg0->work[2] = D_80100E18_114A38_shared_board[D_80102C0D_11682D_shared_board] - 1;
                    }
                }
            }
        }
        break;
    case 2:
        if (arg0->work[3] != 0) {
            arg0->work[3]--;
        } else {
            D_800CC4A0_CD0A0.recentMinigames[D_80102C0D_11682D_shared_board][D_800CC3DC_CCFDC.unk_04[D_80102C0D_11682D_shared_board]] = D_80102C08_116828_shared_board[arg0->work[2]];
            D_800CC3DC_CCFDC.unk_04[D_80102C0D_11682D_shared_board]++;
            
            if (_CheckFlag(0x20) != 0) {
                D_800CC3DC_CCFDC.unk_04[D_80102C0D_11682D_shared_board] = (D_800CC3DC_CCFDC.unk_04[D_80102C0D_11682D_shared_board] % (s32) D_80100E28_114A48_shared_board[D_80102C0D_11682D_shared_board]);
            } else {
                D_800CC3DC_CCFDC.unk_04[D_80102C0D_11682D_shared_board] = (D_800CC3DC_CCFDC.unk_04[D_80102C0D_11682D_shared_board] % (s32) D_80100E20_114A40_shared_board[D_80102C0D_11682D_shared_board]);
            }
            GWMgNoSet(D_80102C08_116828_shared_board[arg0->work[2]]);
            if (GwSystem.current_board_index != 6) {
                func_800E5B90_F97B0_shared_board();
                func_800DF8B4_F34D4_shared_board();
            }
        }
        arg0->rot.z += 1.0f;
        if (arg0->rot.z >= 13.0f) {
            arg0->rot.z -= 13.0f;
        }
        break;
    }
    if (D_80102C12_116832_shared_board != -1) {
        
        for (i = 0; !(arg0->rot.z < (f32) *D_80100E94_114AB4_shared_board[i]); i++) {}
        
        func_80054904_55504(D_80102C12_116832_shared_board, 0,
            (D_80100E94_114AB4_shared_board[i][1] + 50),
            (D_80100E8C_114AAC_shared_board[D_80102C0D_11682D_shared_board] + (arg0->work[1] * 20)));
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DF7F4_F3414_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DF854_F3474_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DF8B4_F34D4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DF9EC_F360C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800DFAD4_F36F4_shared_board);

//TODO: this function is a confusing mess. BUG_FIX macros should work to make it act correctly?
void func_800DFBA8_F37C8_shared_board(s32 arg0) {
    Sp18Struct sp18;
    ItemSlotEntry* entry;
    omObjData* obj;
    s32 category;
    s32 item;
    s32 forbidCount;
    s32 count;
    s32 i;
    s32 j;
    s32 k;

    sp18.rectTable = D_801020B0_115CD0_shared_board;
    sp18.notRectTable1 = D_801020C8_115CE8_shared_board;
    sp18.notRectTable2 = D_801020E0_115D00_shared_board;

    switch (arg0) {
        case -1:
            category = func_800F52C4_108EE4_shared_board();
            if (category == -1) {
                category = 3;
            }
            break;
        case 0:
        default:
            category = 3;
            break;
        case 1:
            category = 4;
            break;
        case 2:
            category = 5;
            break;
    }

    D_80102C0D_11682D_shared_board = category;

    for (i = 0; i < D_80100E18_114A38_shared_board[category]; i++) {
        entry = &D_80102BD0_1167F0_shared_board[i];

        #ifdef BUG_FIX
        //new way to get xy and width/height. Original code crashes for some reason but this logic works out the same
        entry->x = D_801020B0_115CD0_shared_board.rects[category]->x;
        entry->y = D_801020B0_115CD0_shared_board.rects[category]->y + (i * 20);
        entry->w = D_801020B0_115CD0_shared_board.rects[category]->w;
        entry->h = D_801020B0_115CD0_shared_board.rects[category]->h;
        #else
        entry->x = sp18.rectTable.rects[category][i].x;
        entry->y = sp18.rectTable.rects[category][i].y;
        entry->w = sp18.rectTable.rects[category][i].w;
        entry->h = sp18.rectTable.rects[category][i].h;
        #endif

        entry->obj = func_8005A968_5B568(
            (entry->x + (entry->w / 2)),
            (entry->y + (entry->h / 2)),
            entry->w,
            entry->h,
            0, 4);
        func_8005BE30_5CA30(entry->obj, 0x2328);
        func_80060144_60D44(entry->obj);
        func_8005BCA4_5C8A4(entry->obj, entry->w / 2, entry->h / 2);
        func_8005BEE0_5CAE0(entry->obj, 0);

        while (1) {
            #ifdef BUG_FIX
            if (_CheckFlag(0x20)) {
                D_80102C08_116828_shared_board[i] = ((u8*)D_801020E0_115D00_shared_board.notRects[category])[MBRand(D_80100EF4_114B14_shared_board[category])];
            } else {
                D_80102C08_116828_shared_board[i] = ((u8*)D_801020C8_115CE8_shared_board.notRects[category])[MBRand(D_80100EEC_114B0C_shared_board[category])];
            }
            #else
            if (_CheckFlag(0x20)) {
                D_80102C08_116828_shared_board[i] = sp18.notRectTable2.notRects[category]->x[MBRand(D_80100EF4_114B14_shared_board[category])];
            } else {
                D_80102C08_116828_shared_board[i] = sp18.notRectTable1.notRects[category]->x[MBRand(D_80100EEC_114B0C_shared_board[category])];
            }
            #endif
    
            for (j = 0; j < i; j++) {
                if (j == i) {
                    continue;
                }
                if (D_80102C08_116828_shared_board[j] == D_80102C08_116828_shared_board[i]) {
                    break;
                }
            }
            
            if (j != i) {
                continue;
            }

            forbidCount = _CheckFlag(0x20) ? D_80100E28_114A48_shared_board[category] : D_80100E20_114A40_shared_board[category];
            for (k = 0; k < forbidCount; k++) {
                if (D_80102C08_116828_shared_board[i] == D_800CC4A0_CD0A0.recentMinigames[category][k]) { 
                    break;
                }
            }
    
            if (k != forbidCount) {
                continue;
            }
    
            if (BoardGetTurnTier(-1) == 0) {
                item = D_80102C08_116828_shared_board[i];
                if (item == 0x11) {
                    continue;
                }
    
                if (item == ((item >= 0x12) ? 0x1C : 9)) {
                    continue;
                }
            }
            break;
        }

        func_8005D2D4_5DED4(entry->obj);

        if (GWMgUnlockCheck(D_80102C08_116828_shared_board[i] - 1) != 0) {
            func_8005B43C_5C03C(entry->obj, D_80102C08_116828_shared_board[i] + 0x46FF, -2, 4);
        } else {
            func_8005B43C_5C03C(entry->obj, 0x4748, -2, 4);
        }
        
        func_8005C02C_5CC2C(entry->obj, D_80100E9B_114ABB_shared_board[D_80102C08_116828_shared_board[i]]);
        func_8005BDFC_5C9FC(entry->obj, 0);
    }

    obj = omAddObj(-0x8000, 0U, 0U, -1, func_800DED3C_F295C_shared_board);
    D_80102C04_116824_shared_board = obj;
    obj->work[0] = 3;
    obj->work[1] = 5;
    obj->trans.y = 0.0f;
    obj->scale.x = 10.0f;
    obj->scale.y = 0.0f;
    obj->rot.z = 0.0f;
    func_800DF9EC_F360C_shared_board();

    func_80055420_56020(D_80102C0E_11682E_shared_board, 0,
        D_80100E30_114A50_shared_board[D_80102C0D_11682D_shared_board][0],
        D_80100E30_114A50_shared_board[D_80102C0D_11682D_shared_board][1],
        D_80100E30_114A50_shared_board[D_80102C0D_11682D_shared_board][2]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E00EC_F3D0C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E00FC_F3D1C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E01DC_F3DFC_shared_board);

ItemRectTable const D_801020B0_115CD0_shared_board = {
    {
    &D_80100E5C_shared_board,
    &D_80100E44_shared_board,
    &D_80100E44_shared_board,
    &D_80100E44_shared_board,
    &D_80100E44_shared_board,
    &D_80100E5C_shared_board
    }
};

DefinitelyNotItemRectTable const D_801020C8_115CE8_shared_board = {
    {
    (DefinitelyNotItemRect*)D_80100DA0_shared_board,
    (DefinitelyNotItemRect*)D_80100DC0_shared_board,
    (DefinitelyNotItemRect*)D_80100DD4_shared_board,
    (DefinitelyNotItemRect*)D_80100DF4_shared_board,
    (DefinitelyNotItemRect*)D_80100DE8_shared_board,
    (DefinitelyNotItemRect*)D_80100E04_shared_board
    }
};

DefinitelyNotItemRectTable const D_801020E0_115D00_shared_board = {
    {
    (DefinitelyNotItemRect*)D_80100DB4_shared_board,
    (DefinitelyNotItemRect*)D_80100DCC_shared_board,
    (DefinitelyNotItemRect*)D_80100DE0_shared_board,
    (DefinitelyNotItemRect*)D_80100DFC_shared_board,
    (DefinitelyNotItemRect*)D_80100DF0_shared_board,
    (DefinitelyNotItemRect*)D_80100E10_shared_board
    }
};

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0534_F4154_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0A14_F4634_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0A64_F4684_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0C3C_F485C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0C94_F48B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0F84_F4BA4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E0FE0_F4C00_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E11C0_F4DE0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E1230_F4E50_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/F2910", func_800E13F0_F5010_shared_board);
