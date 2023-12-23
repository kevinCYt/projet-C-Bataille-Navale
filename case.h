#ifndef CASE_H
#define CASE_H
;
/**
 * @file case.h
 * @brief Header file containing the enum for different cases on the game board.
 */

/**
 * @enum CasePlateau
 * @brief Represents different cases on the game board.
 *
 * This enum defines the possible values for each case on the game board.
 * - WATER: Represents a water cell.
 * - WATER_SHOT: Represents a water cell that has been shot.
 * - BOAT: Represents a cell occupied by a boat.
 * - WRECK: Represents a cell where a boat has been hit and wrecked.
 */
enum CasePlateau {
    WATER = 0,     /**< Represents a water cell. */
    WATER_SHOT = -1,/**< Represents a water cell that has been shot. */
    BOAT = 1,      /**< Represents a cell occupied by a boat. */
    WRECK = 10     /**< Represents a cell where a boat has been hit and wrecked. */
};

#endif
