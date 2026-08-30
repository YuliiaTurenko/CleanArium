# CleanArium

CleanArium is a aquarium monitoring and management system designed as a full-stack application. Developed as a comprehensive university project, this project focuses on mastering code refactoring, architectural patterns, and core engineering principles like OOP, SOLID, and DRY. It encompasses the full system lifecycle — from initial planning, database design, backend, frontend, and mobile development to basic IoT integration, deployment, and scaling.

> Project status: The project is currently in development. The core functionality, web, mobile, basic IoT-client, containerization, and infrastructure management features have already been implemented, while some parts of the overall system can still be expanded and improved.


## Overview
The main goal of CleanArium is to provide a convenient web and mobile applications for working with aquarium-related data while demonstrating modern approaches like application architecture, secure API, orchestration, and deployment management.
This system is designed to automate and monitor aquarium parameters using IoT technologies. It provides:
- data collection from sensors connected to the IoT device (temperature, dissolved oxygen level and pH);
- transmission of this data to the server part;
- storage, processing and visualization of information;
- the ability to remotely control aquarium equipment (turning on/off lighting, filter, heater);
- obtaining analytics and forecasts based on measured parameters;
- generation of notifications about deviations from normal indicators.

The user receives a system that helps maintain stable conditions without constant manual intervention.

## Technology Stack
### Backend
-   .NET 8 (C#)
-   ASP.NET Core Web API
-   Entity Framework Core
-   Microsoft SQL Server
-   JWT Authentication
-   Swagger / OpenAPI
-   Kubernetes .NET Client

### Frontend
-   React
-   TypeScript
-   Axios
-   CSS
-   Nginx

### Mobile
-   Flutter
-   Dart
-   Dio library
-   Android Emulator

### DevOps / Infrastructure
-   Docker
-   Kubernetes
-   Kubernetes Deployments
-   Kubernetes Services
-   Pods
-   Replica-based horizontal scaling
-   Kubernetes API

### IoT:
-   Wokwi Simulator
-   ESP32 DevKit
-   C++

### Architecture
-   Clean Architecture
-   Domain/Application/Persistence/Infrastructure/API separation
-   Repository Pattern
-   Service Layer
-   Dependency Injection
-   DTO Pattern
-   Middleware
-   Background Services


## Main Features
**Backend functionality**:
- REST API creation for interaction with web and mobile clients;
- user registration and authentication;
- security: use of JWT tokens, two-factor authentication;
- access control to personal data;
- CRUD operations for aquariums, devices, commands and rules;
- data import and export to CSV, JSON or PDF;
- data processing received from IoT clients via HTTP;
- saving the history of indicators in the database;
- notification mechanism when parameters go beyond the norm;
- processing of warning rules with verification of sensor values;
- analysis of historical sensor values ​​and frequency of triggering of warnings;
- generation of graphs and history;
- role management (assignment and removal of the moderator role);
- management of system parameters (limits on the number of aquariums, devices, rules and scheduled commands);
- user activity statistics.

**IoT client functionality**:
- sending sensor data to the server via HTTP at a certain interval;
- sending a request to receive commands at a certain interval;
- executing and analyzing commands depending on the type of device;
- creating notifications when emergencies occur
- reading data from sensors (temperature, pH, etc.).

**Web client functionality**:
- authorizing and managing the user profile;
- viewing sensor indicators;
- displaying the status of equipment and analytics;
- manual remote control of devices;
- adding, editing and deleting aquariums;
- managing connected devices (binding/disconnecting);
- setting threshold values ​​(Threshold) for sensors;
- creating and editing warning rules;
- setting automatic commands;
- viewing notifications;
- data visualization in the form of graphs;
- viewing and filtering of historical data.

**Mobile client functionality**:
- login and synchronization with the user account;
- receiving and viewing push notifications;
- quick actions (for example, turning the device on/off with one click);
- viewing the list of aquariums and quickly switching between them;
- displaying key indicators.

---------------------------------------------------------------------
## Backend
The ASP.NET Core API layer contains:
-   controllers;
-   middleware;
-   dependency injection configuration;
-   authentication and authorization configuration;
-   Swagger/OpenAPI configuration;
-   application startup;
-   HTTP pipeline configuration.

Several common architectural patterns are used throughout the backend.
**Repository Pattern**: Repositories abstract database access from application logic and provide a consistent way to work with persisted entities.
**CQRS Pattern**: ...
**Dependency Injection**: ASP.NET Core Dependency Injection is used to register and resolve services, repositories, database contexts, and infrastructure components.
**DTO Pattern**: DTOs are used to define data transferred between the API and clients without exposing internal domain or persistence models directly.
**Middleware**: Custom middleware is used for cross-cutting concerns such as centralized exception handling.

## API Documentation
The backend provides interactive API documentation using Swagger / OpenAPI. Swagger is used during development and demonstration to:
-   inspect available endpoints;
-   test API operations;
-   provide JWT authentication for protected endpoints;
-   verify backend functionality independently of the frontend.
-   
## Database
The project uses **Microsoft SQL Server** with **Entity Framework Core**. Database schema changes are managed through EF Core migrations.
During application startup, the database migration process can be executed before the application begins serving requests. This ensures that the database schema is synchronized with the version of the application being deployed.
The application also includes an administrator seeding mechanism for creating the initial administrative user.

## Frontend
The frontend communicates with the ASP.NET Core API through HTTP requests and uses JWT authentication for protected operations.
The application also contains an administrative interface for infrastructure management.
The project is built on the principle of separation of responsibilities – the structure is organized in such a way as to clearly separate the data logic from the visual representation. Three access levels are implemented:
- user interface: focused on managing aquariums, devices, etc. and personalizing settings;
- administrator interface: provides full control over system parameters, security, and user management;
- moderator interface: an environment for monitoring the system.

Particular attention in the project is paid to the dynamics of application state changes
depending on the authorization status. Since the security and correctness of redirects are critical, the logic of the operation of protected routes (Protected Routes) and the Role Redirect mechanism required separate visualization.
Switching between Ukrainian and English languages ​​has been implemented. All text translations are placed in separate localization JSON files.

## Mobile app
The main functional modules of the system have been implemented in the mobile client. User authorization and registration pages, a main page with a list of aquariums, a page of aquarium and device details, modules for managing alarm rules (Alarm Rules), scheduled commands (Scheduled Commands), as well as a page of notifications (Notifications) have been created. The main functions have been implemented using dialog boxes and interactive interface elements. To improve the usability of the system, internationalization support has been added. The application supports Ukrainian and English languages.

## IoT-client
The IoT client is implemented on the basis of ESP32 and interacts with the server part via HTTP requests. The server part provides a REST API that allows the IoT device to: transmit sensor data (SensorData), receive commands for execution, and notify the server about executed commands (ExecutedCommand). 
Since a simulator is used, real physical sensors are replaced by software emulation. Values ​​are generated in acceptable ranges using pseudo-random numbers. The IoT client can behave differently depending on the type. This allows emulating different types of IoT devices without changing the architecture. 
The IoT client performs simple local data processing: calculates the average temperature value, based on which it calculates the conditional danger level. This demonstrates pre-processing of data without the participation of the server.

## Docker
The application is containerized using Docker. The main components are deployed as separate containers:
-   ASP.NET Core API;
-   React frontend;
-   Microsoft SQL Server.

Database Container: SQL Server runs in its own container and is connected to the backend through the Kubernetes service network.
Persistent database storage is provided through Docker/Kubernetes storage configuration so that container recreation does not inherently mean losing the database contents.

## Kubernetes Administration Panel
One of the main extensions developed for the project is the Deployment & Scaling administration panel. The administrative functionality includes:
-   viewing Kubernetes Deployments;
-   viewing Pods;
-   inspecting deployment and pod status;
-   changing the number of Deployment replicas;
-   viewing pod logs;
-   interacting with the Kubernetes cluster through the backend.

This provides a convenient management layer over the Kubernetes infrastructure.
The project also includes an automatic configuration generation component. The administrator can provide parameters such as:
-   application/deployment name;
-   Docker image;
-   number of replicas;
-   container/service port.

## Horizontal Scaling
The application supports horizontal scaling through Kubernetes Deployments. For example, increasing the number of replicas of an API Deployment causes Kubernetes to run multiple instances of the backend. This makes it possible to distribute incoming requests across multiple application instances and reduces dependence on a single running Pod. Kubernetes also maintains the desired number of replicas and can recreate a Pod if one of the replicas terminates unexpectedly.

## Deployment
The Microsoft Azure cloud platform was chosen to deploy the created project. This choice is due to the need to ensure high availability, security, and scalability of the system. Azure automatically ensures the viability of the application and integration with the .NET runtime environment. Thus, the following stages were performed for deployment: 
- creating a Web App to host the .NET Web API; 
- creating an Azure SQL Database to store data; 
- setting up a connection between the Web App and the database via a connection string; 
- downloading the server-side code from the repository and deploying it to Azure. 

Instead of a local SQL Server, the Azure SQL cloud solution was used. It provides automatic schema management and security. Database migrations are performed automatically when the application is launched, which allows you to maintain the current database structure without manual intervention. Automation via CI/CD (GitHub Actions): the project is configured for automatic deployment. Each 'push' to the repository triggers a build and deployment process in Azure, which minimizes human intervention and speeds up the delivery of new features.

-------------------------------------------------------------------
## Learning Outcomes
Working on CleanArium provided practical experience with several areas of modern software development:
-   designing a layered backend using Clean Architecture;
-   building REST APIs with ASP.NET Core;
-   working with Entity Framework Core and SQL Server;
-   implementing JWT authentication and role-based authorization;
-   building frontend on React;
-   building mobile app on Flutter;
-   learning basics of IoT while working with ESP32
-   deploying on Azure
-   containerizing with Docker;
-   working with Deployments, Pods, Services and replicas;
-   implementing horizontal scaling.

Although the project is not yet fully finished, it provides a solid foundation for further development, including more advanced monitoring, resource-based autoscaling, CI/CD integration, and more comprehensive infrastructure automation.
