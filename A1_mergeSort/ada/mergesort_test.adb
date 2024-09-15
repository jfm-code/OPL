-- Merge sort in Ada, to build the program: gnatmake mergesort_test.adb
-- To see the output: ./mergesort_test
-- Parameters are hard-coded

with Ada.Text_Io; use Ada.Text_Io;
with Mergesort; 

procedure Mergesort_Test is
   type List_Type is array(Positive range <>) of Integer;
   package List_Sort is new Mergesort(Integer, Positive, List_Type);
   procedure Print(Item : List_Type) is
   begin
      for I in Item'range loop
         Put(Integer'Image(Item(I)));
      end loop;
      New_Line;
   end Print;
   
   List : List_Type := (170, 45, 75, -90, -802, 24, 2, 66);
begin
   Put_Line("Original List:");
   Print(List);
   Put_Line("Sorted List:");
   Print(List_Sort.Sort(List));
end Mergesort_Test;