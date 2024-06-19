# Sweets Inventory Management System

A console-based application in C for managing an inventory system for sweets. This project includes functionalities for adding, viewing, modifying, and deleting sweets, along with user authentication and order processing features.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Admin Module**: Manage sweets inventory through CRUD operations (Create, Read, Update, Delete).
- **User Authentication**: Secure login system for administrators with password management.
- **Order Processing**: Create orders based on available stock quantities.
- **File Handling**: Utilizes file operations (`fopen`, `fwrite`, `fread`) for data storage and retrieval.
- **Modular Design**: Organized into separate modules (`admin_curd.c`, `change_pwd.c`, `log_in.c`, `menu_view.c`) for clarity and maintenance.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/nitish-rAogopal/sweetMgmt.git
   
2. **Compile the program:**
   ```bash
   gcc main.c admin_curd.c change_pwd.c log_in.c menu_view.c -o menu_view.exe
   
3. **Run the program:**
   
   ``bash
   ./admin.exe
   ./user_order.exe

## Usages

- Log in as an administrator to access the admin module.
- Choose options to add, view, modify, or delete sweets from the inventory.
- Manage passwords and security questions using the password management module.
- Create orders for sweets and view detailed inventory information.

## File Structure

   ```
    sweets-inventory/
    ├── admin_driver.c       
    ├── admin_curd.c         
    ├── change_pwd.c         
    ├── log_in.c             
    ├── menu_view.c          
    ├── menu2.c              
    ├── user.c               
    └── user_order.c

## Contributing

Contributions are welcome! Please follow these steps to contribute:

1. **Fork the repository.**
   
2. **Create your feature branch**
     ```sh
     git checkout -b feature/your-feature-name

3. **Commit your changes**

     ```sh
     git commit -am 'Add some feature

4. **Push to the branch**

     ```sh
     git push origin feature/your-feature-name

5. **Open a pull request.**
  
## Author

Nitish Kumar <br>
nitish.raogopal@gmail.com | https://github.com/nitish-rAogopal/<br>
Project link: https://github.com/nitish-rAogopal/sweetMgmt/

## License

This project is licensed under the MIT License. See the LICENSE file for details.
   ```
   This `README.md` file includes all the necessary sections and is formatted for clarity and ease of use on GitHub.
