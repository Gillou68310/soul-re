.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel CheckCallback
/* AA3A0 800B9BA0 0D80023C */  lui        $v0, %hi(D_800CC916)
/* AA3A4 800B9BA4 16C94294 */  lhu        $v0, %lo(D_800CC916)($v0)
/* AA3A8 800B9BA8 0800E003 */  jr         $ra
/* AA3AC 800B9BAC 00000000 */   nop
.size CheckCallback, . - CheckCallback
