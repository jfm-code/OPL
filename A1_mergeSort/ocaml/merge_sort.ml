(* Merge sort in OCaml. To run type ocaml merge_sort.ml *)
(* Parameters are hard-coded *)

let rec split_at n xs =
  match n, xs with
      0, xs ->
        [], xs
    | _, [] ->
        failwith "index too large"
    | n, x::xs when n > 0 ->
        let xs', xs'' = split_at (pred n) xs in
          x::xs', xs''
    | _, _ ->
        invalid_arg "negative argument"

let rec merge_sort cmp = function
    [] -> []
  | [x] -> [x]
  | xs ->
      let xs, ys = split_at (List.length xs / 2) xs in
        List.merge cmp (merge_sort cmp xs) (merge_sort cmp ys)

(* Main code to execute and print the original and sorted list *)
let _ =
  let original_list = [170; 45; 75; -90; -802; 24; 2; 66] in
  let sorted_list = merge_sort compare original_list in

  Printf.printf "Original list: ";
  List.iter (Printf.printf "%d ") original_list;
  print_endline "";

  Printf.printf "Sorted list: ";
  List.iter (Printf.printf "%d ") sorted_list;
  print_endline ""