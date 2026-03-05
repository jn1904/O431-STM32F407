#include "IWDG.h"

namespace O431 {
    WATCHDOG::WATCHDOG() {
        hiwatchdog = &hiwdg;
        HAL_IWDG_Init(hiwatchdog);
        HAL_IWDG_Refresh(hiwatchdog);
    }

    WATCHDOG::~WATCHDOG() {
        return;
    }

    void WATCHDOG::feed_Dog() {
        HAL_IWDG_Refresh(hiwatchdog);
    }
} // O431