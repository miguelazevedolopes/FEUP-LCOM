#ifndef _LCOM_I8042_H_
#define _LCOM_I8042_H_


#define KBC_IRQ 1         /**< @brief Keyboard IRQ line */
#define OUT_BUF 0x60      /**< @brief Keyboard output buffer port */
#define CMD_ARGS_REG 0x60 /**< @brief Keyboard command arguments register */
#define STATUS_REG 0x64   /**< @brief Keyboard status register */
#define CMD_REG 0x64      /**< @brief Keyboard commands register */

#define DELAY_US 20000 /**< @brief Delay until the timer responds to a command */

//Important keys (the direction keys use the byte 0xE0)
#define ESC_KEY 0x81            /**< @brief Esc key breakcode */
#define FIRST_OF_TWO_BYTES 0xE0 /** <@brief First byte of two byte scan code */
#define UP_KEY 0x48             /**< @Up key makecode; breakcode - 0xC8 */
#define UP_KEY_BREAK 0xC8 
#define DOWN_KEY 0x50           /**< @Down key makecode; breakcode - 0xD0 */
#define DOWN_KEY_BREAK 0Xd0
#define LEFT_KEY 0x4b           /**< @Left key makecode; breakcode - 0xCB */
#define RIGHT_KEY 0x4d          /**< @Right key makecode; breakcode - 0xCD */
#define RIGHT_KEY_BREAK 0xcd
//KBC Status register
#define KBC_PARE BIT(7)  /**< @brief Status register parity error */
#define KBC_TIMEO BIT(6) /**< @brief Status register timeout error */
#define KBC_AUXB BIT(5)  /**< @brief Status register mouse data */
#define KBC_KEYL BIT(4)  /**< @brief Status register keylock/inhibit flag */
#define KBC_CD BIT(3)    /**< @brief Status register command/A2 input line */
#define KBC_SYSF BIT(2)  /**< @brief Status register system flag */
#define KBC_INPB BIT(1)  /**< @brief Status register input buffer flag */
#define KBC_OUTB BIT(0)  /**< @brief Status register output buffer flag*/

//KBC Commands
#define READ_CMD_B 0x20   /**< @brief Returns command byte */
#define WRITE_CMD_B 0x60  /**< @brief Writes command byte (must pass command byte as argument to port 0x60) */
#define CHECK_KBC 0xAA    /**< @brief Self-test: returns 0x55 if OK, returns 0xFC if error */
#define CHECK_KB_IFC 0xAB /**< @brief Check Keyboard interface : returns 0 if OK */
#define DISABLE_KBD 0xAD  /**< @brief Disables Keyboard interface */
#define ENABLE_KBS 0xAE   /**< @brief Enables Keyboard interface */

//Command Byte bits
#define ENABLE_KBD_IR BIT(0) /**< @brief Enables Keyboard interrupts on OBF */

#define ENABLE_DATA_REPORT 0xF4
#define DISABLE_DATA_REPORT 0xF5
#define MOUSE_IRQ_LINE 0x0C
#define OUTPUT_BUFFER 0x60
#define STATUS_REGISTER 0x64 
#define COMMAND_REGISTER 0x64
#define COMMAND_ARGUMENT 0x60
#define KBC_WRITE_COMMAND 0x60
#define KBC_READ_COMMAND 0x20
#define MOUSE_WRITE_COMMAND 0xD4
#define ACK 0xFA
#define NACK 0xFE
#define ERROR 0xFC

#endif
