# Hospital Patient Management System - Balanced Three-Way Team Breakdown


## Part 1: Data Structures and Patient Operations
**Team Member 1 Responsibilities:**

1. Design and implement the `Patient` class/struct
   - Define attributes: firstName, lastName, SSN, status (regular/critical)
   - Implement constructors, accessors, mutators, and any needed operators

2. Implement the queue data structure using linked list nodes
   - Create the `Node` class for queue elements
   - Implement core queue functionality (enqueue, dequeue, isEmpty, etc.)
   - Add priority handling for critical patients

3. Implement the following clinic operations:
   - Add regular patient functionality
   - Add critical patient functionality (with priority)
   - List all patients functionality
   - Associated console input/output for these operations

4. Unit test these components to ensure they work correctly

## Part 2: Queue Management and File I/O
**Team Member 2 Responsibilities:**

1. Implement remaining clinic operations:
   - Take out patient for operation (dequeue with priority rules)
   - Cancel patient by SSN (remove from middle of queue)
   - Exit department functionality
   - Associated console input/output for these operations

2. Implement file input operations
   - Read the patient.csv file at program start
   - Parse input data
   - Validate clinic names and SSN format
   - Handle initial patient loading

3. Implement clinic capacity management
   - Track and enforce the 10-patient limit per clinic
   - Generate appropriate error messages

4. Unit test these components to ensure they work correctly

## Part 3: Program Integration and Transaction Logging
**Team Member 3 Responsibilities:**

1. Implement the `Clinic` base class structure
   - Define the class hierarchy
   - Implement derived classes for each department (HC, PC, PSC)
   - Ensure proper inheritance relationships

2. Implement transaction logging
   - Create and maintain the transaction log file
   - Format transaction messages for all operations
   - Group transactions by clinic
   - Generate end-of-day report

3. Implement menu system and program flow
   - Main clinic selection menu
   - Department action menu
   - End-of-day processing
   - Next-day file generation

4. Final integration and testing of the complete system

## Shared Responsibilities for All Team Members:
- Document your code with comments, including pre- and post-conditions for functions
- Participate in code reviews of each other's work
- Contribute to the final presentation/demo
- Maintain the document explaining each team member's role and completed work

This rebalanced breakdown ensures each team member has work of similar complexity and scope:

- Team Member 1 focuses on core data structures and fundamental patient operations
- Team Member 2 focuses on advanced queue operations and file input
- Team Member 3 focuses on class structure, logging, and system integration
