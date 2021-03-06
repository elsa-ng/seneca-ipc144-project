# seneca-ipc144-project
<p><b>Winter 2017 IPC144 Grocery Store Inventory System</b></p>

<p><b>Keep Calm, Code On and Don't Plagiarize!</b><br/>
It is okay to read someone's code and learn from it. If you find my code useful and would like to include it in your solution then please reference it.</p>

<div>
  <b>Overview</b><br/>
  An inventory system that keeps track of items available and ensure stock does not fall below a specific count.
  The system tracks the following information about an item:
  <ul>
    <li>SKU number</li>
    <li>Item name (max of 20 characters)</li>
    <li>Quantity in stock</li>
    <li>Minimum quantity (warning is generated when quantity in stock falls below or equal to this number)</li>
    <li>Price of item</li>
    <li>Is item taxed</li>
  </ul>The system performs the following tasks:
  <ul>
    <li>Print a detailed list of all the items in the inventory</li>
    <li>Search and display an item by its SKU number</li>
    <li>Checkout an item to be delivered to the shelf for sale</li>
    <li>Add to stock items that are recently purchased for inventory (add to their quantity)</li>
    <li>Add a new item to the inventory or update an already existing item</li>
    <li>Delete an item from the inventory (optional for extra marks)</li>
    <li>Search for an item by its name (optional for extra marks)</li>
    <li>Sort Items by Name (optional for extra marks)</li>
  </ul>
</div>

<div>
  <b>Milestone 1 - User Interface Tools and App Interface</b><br/>
  Code the interface using knowledge learned in previous lectures such as:
  <ul>
    <li>Selection constructs such as optional sequence, alternative sequence and conditional expression</li>
    <li>Iteration constructs such as while, do while and for</li>
    <li>Nested constructs</li>
    <li>I/O Functions</li>
  </ul>
</div>

<div>
  <b>Milestone 2 - Item Input and Output</b><br/>
  Build on milestone 1 and implement item related functions using knowledge learned in recent lectures such as:
  <ul>
    <li>String Library</li>
    <li>Arrays</li>
    <li>Structures</li>
    <li>Pointers</li>
  </ul>
</div>

<div>
  <b>Milestone 3 - Item Storage and Retrieval in Array</b><br/>
  Build on milestone 2 and implement functions that work with an array of items to perform the following:
  <ul>
    <li>Search through an array of items using an item's SKU</li>
    <li>Update an item's information</li>
    <li>Add a new item the array</li>
  </ul>
</div>

<div>
  <b>Milestone 4 - File IO</b><br/>
  Build on milestone 3 and implement functions that work with file input/output:
  <ul>
    <li>Save item(s) to a text file</li>
    <li>Load item(s) from a file</li>
  </ul>
</div>

<div>
  <b>Milestone 4a - Final Assembly</b><br/>
  Putting it all together by: 
  <ul>
    <li>Add a main function to 144_ms4.c</li>
    <li>Modify the GroceryInventorySystem function (done in milestone 1)</li>
    <li>Test the application using black-box and white-box techniques to ensure application executes as intended</li>
    <li>Document/comment on errors encountered, fixes implemented, and additional features added</li>
  </ul>
</div>

<div>
  <b>Milestone 5 - The Extras/Bonuses: Delete and Search by Name</b><br/>
  Build on the final assembly and implement the delete and search by name functions.
</div>