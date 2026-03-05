#ifndef F407_IWDG_H
#define F407_IWDG_H

#ifdef __cplusplus
extern "C" {
#endif
#include "iwdg.h"

    namespace O431 {
        class WATCHDOG {
        public:
            WATCHDOG();
            ~WATCHDOG();

            void feed_Dog();
        private:
            IWDG_HandleTypeDef* hiwatchdog;

        };
    } // O431
#ifdef __cplusplus
}
#endif
#endif //F407_IWDG_H