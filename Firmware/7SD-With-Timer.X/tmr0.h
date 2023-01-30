#ifndef TMR0_H
#define TMR0_H

/**
  Section: Included Files
 */

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C"
{

#endif

/**
  Section: TMR0 APIs
 */

/**
  @Summary
    Timer Interrupt Handler

  @Description
    This is a function pointer to the function that will be called during the ISR

  @Preconditions
    Initialize  the TMR0 module with interrupt before calling this ISR.

  @Param
    None

  @Returns
    None
 */
extern void (*tmr0_isr_handler)(void);

/**
  @Summary
    Initializes the TMR0.

  @Description
    This function initializes the TMR0 Registers.
    This function must be called before any other TMR0 function is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    
	
  @Example
    <code>
    main()
    {
        // Initialize TMR0 module
        tmr0_init();

        // Do something else...
    }
    </code>
 */
void tmr0_init(void);

/**
  @Summary
    This function starts the TMR0.

  @Description
    This function starts the TMR0 operation.
    This function must be called after the initialization of TMR0.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TMR0 module

    // Start TMR0
    tmr0_start();

    // Do something else...
    </code>
 */
void tmr0_start(void);

/**
  @Summary
    This function stops the TMR0.

  @Description
    This function stops the TMR0 operation.
    This function must be called after the start of TMR0.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TMR0 module
    tmr0_init();

    // Start TMR0
    tmr0_start();

    // Do something else...

    // Stop TMR0;
    tmr0_stop();
    </code>
 */
void tmr0_stop(void);

/**
  @Summary
    Timer Interrupt Service Routine

  @Description
    Timer Interrupt Service Routine is called by the Interrupt Manager.

  @Preconditions
    Initialize  the TMR0 module with interrupt before calling this ISR.

  @Param
    None

  @Returns
    None
 */
void tmr0_isr(void);


/**
  @Summary
    Set Timer Interrupt Handler

  @Description
    This sets the function to be called during the ISR

  @Preconditions
    Initialize the TMR0 module with interrupt before calling this.

  @Param
    Address of function to be set

  @Returns
    None
 */
void tmr0_set_isr_handler(void (* interrupt_handler)(void));

#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif

#endif // TMR0_H
/**
 End of File
 */