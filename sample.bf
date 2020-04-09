+                       // cell nº 0 is set to 1
>++++++++++             // cell nº 1 is set to 10
[                       // starts loop checking for 1
    >++++++++           // cell nº 2 is set to 80
    >+++                // cell nº 3 is set to 30
    <<-                 // cell nº 1 is decremented
]                       // ends loop checking for 1
++                      // cell nº 1 is set to 2
[                       // cell nº 1
    >++++.-----.        // cell nº 2 is set to 84 print then is set to 79 print
    <<                  // cell nº 0 is set to 1
    [                   // starts loop checking for 0 
        >>-.++          // cell nº 2 is set to 78 then is set to 79
        <<-             // cell nº 0 is decremented
    ]                   // ends checking for 0
    >-                  // cell nº 1 is decremented
]                       // ends loop checking for 1
>>++.                   // cell nº 3 print
<<++                    // cell nº 1 is set to 2
[                       // starts loop checking for 1
    >-----              // cell nº 2 is set to 69
    <-                  // cell nº 1 is decremented
]                       // ends loop checking for 1
>.                      // cell nº 2 print
<+++                    // cell nº 1 is set to 3
[                       // starts loop checking for 1
    >++                 // cell nº 2 is set to 75
    <-                  // cell nº 1 is decremented
]                       // ends loop checking for 1
>+.                     // cell nº 2 is set to 76 print
>.                      // cell nº3 print
<+++++.++++.            // cell nº2 is set to 81 print and then is set to 85 print
<++++                   // cell nº1 is set to 4
[                       // starts loop checking for 1
    >----               // cell nº 2 is set to 69
    <-                  // cell nº 1 is decremented
]                       // ends loop checking for 1
>.                      // cell nº 2 print
>.                      // cell nº 3 print
<<+++                   // cell nº 1 is set to 3
[                       // starts loop checking for 1
    >++                 // cell nº 2 is set to 75
    <-                  // cell nº 1 is decremented
]                       // ends loop checking for 1
>+.+++.                 // cell nº 2 is set to 76 print then is set to 79 print
>.                      // cell nº 3 print
<---.+++                // cell nº 2 is set to 76 print then is set to 79
<++                     // cell nº 1 is set to 2
[                       // starts loop checking for 1
    >-----              // cell nº 2 is set to 69
    <-                  // decrements cell nº 1
]                       // ends loop checking for 1
>.----.                 // cell nº 2 print then is set to 65



