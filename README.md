# InfernoX
### Intelligent Wildfire Emergency Response & Resource Optimization System

## 1. Project Overview

InfernoX is a wildfire emergency response and resource optimization system designed to support the prioritization of wildfire incidents, efficient allocation of emergency resources, and route planning for response teams. The project aims to improve emergency response coordination by providing a structured approach to evaluating incidents and determining appropriate response priorities.

## 2. Problem Statement

Wildfire emergencies can involve multiple incidents occurring simultaneously, each with different levels of severity and risk to nearby populations. Limited availability of firefighting teams, rescue personnel, ambulances, and transportation resources makes it challenging to respond to every incident immediately.

Without systematic prioritization and resource planning, critical incidents may experience delays in receiving assistance. InfernoX addresses this problem by combining incident priority assessment, emergency resource allocation, and route optimization into a unified workflow.

## 3. Project Objectives

- Prioritize wildfire incidents based on severity, population risk, fire spread rate, fire duration, and distance from populated areas.
- Develop a priority scoring mechanism to compare incidents and identify those requiring urgent attention.
- Plan the allocation of available emergency resources according to incident urgency and resource requirements.
- Apply graph-based pathfinding to identify suitable routes for emergency response teams.
- Evaluate the system using different wildfire scenarios to assess the correctness of priority calculations, resource assignments, and route planning.

## 4. Proposed System Approach

The system follows a modular workflow consisting of the following components:

1. **Incident Assessment:** Collect and organize information about wildfire incidents and their associated risk factors.
2. **Priority Calculation:** Calculate priority scores using selected parameters to establish the relative urgency of incidents.
3. **Resource Allocation:** Determine appropriate assignments of available emergency resources based on incident priorities and resource requirements.
4. **Route Optimization:** Represent locations and connecting routes as a graph and use Dijkstra's algorithm to identify shortest paths.
5. **Testing and Validation:** Evaluate the system using sample wildfire scenarios and verify the correctness of its outputs.

These components are intended to work together to support structured decision-making during wildfire emergencies.

## 5. Technology Stack

- **Programming Language:** C++
- **Programming Concepts:** Object-oriented programming and modular design
- **Data Structures and Algorithms:** Priority-based incident assessment, graphs, and Dijkstra's shortest-path algorithm
- **Version Control:** Git and GitHub

## 6. Repository Structure

The repository currently contains the following files:

```text
InfernoX/
├── README.md
└── hospital.cpp
```

- `README.md`: Project overview, objectives, technical approach, and documentation.
- `hospital.cpp`: C++ source code for the current project implementation.

Additional source files, test cases, and documentation may be added as development progresses.

## 7. Setup and Execution

### Prerequisites

- A C++ compiler supporting the C++ standard used by the project, such as GCC.
- A terminal or compatible code editor.

### Compilation


### Compilation

Compile the C++ source file from the project directory:

```bash
g++ hospital.cpp -o infernox
```

### Execution

**On Linux:**

```bash
./infernox
```

**On Windows:**

```powershell
.\infernox.exe
```


These commands assume that `hospital.cpp` contains a valid `main()` function and that all required code is contained in this file. Compilation instructions should be updated if the implementation is split across multiple source files.

## 8. Project Status

Phase 1, covering problem definition, objectives, and initial project planning, has been completed. Phase 2 focuses on developing and refining the system components, integrating the overall workflow, validating the implementation through test scenarios, and completing project documentation.

The implementation status of individual components should be assessed against the current source code as development progresses.

## 9. Expected Outcomes

The expected outcome is a working prototype that demonstrates wildfire incident prioritization, emergency resource allocation, and graph-based route planning. The project will also include relevant test cases, system design documentation, and an evaluation of the prototype using representative wildfire scenarios.

InfernoX is intended as an academic prototype for demonstrating emergency response planning concepts and is not a substitute for validated operational emergency management systems.

## 10. Team Members

- Neerav Bhutowa
- Niti Kumari
- Tanishek Negi
- Vansh Agarwal

