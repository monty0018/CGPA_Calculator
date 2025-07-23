Quiz Application in C++

Description
A simple console-based quiz application written in C++ that loads questions from a text file and allows users to test their knowledge. The application features colorful console output and tracks the user's score.



Features
- Loads questions from an external text file
- Colorful console interface for better user experience
- Case-insensitive answer checking
- Score tracking and final results display
- Simple and intuitive interface

 Requirements
- C++ compiler (g++, clang++, or MSVC)
- Linux/macOS/Windows system (uses `system("clear")` which works on Unix-like systems)

File Structure
```
quiz-app/
├── quizApp.cpp       # Main application source code
├── Quiz.txt          # Questions file (create this with your questions)
└── README.md         # This file
```

How to Use
1. Compile the program:
   ```bash
   g++ quizApp.cpp -o quizApp
   ```
2. Create a `Quiz.txt` file with your questions (see format below)
3. Run the program:
   ```bash
   ./quizApp
   ```

Quiz.txt File Format
The questions file should follow this format for each question:
```
Question text
Option A text
Option B text
Option C text
Option D text
correct_answer_letter  (a, b, c, or d)
```

Example:
```
What is the capital of France?
Paris
London
Berlin
Madrid
a
```

 Customization
You can easily customize:
- The colors by modifying the color functions in the code
- The quiz content by editing Quiz.txt
- The scoring system by modifying the QuizApp class

 Known Issues
- On Windows systems, `system("clear")` should be changed to `system("cls")`
- No input validation for answer format (must enter a, b, c, or d)

Future Improvements
- Add support for multiple quiz files
- Implement a timer for each question
- Add difficulty levels
- Create a score history system

.
