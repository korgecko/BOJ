use std::io;

// 백준 #11720

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let mut string_how_many_digits = buf.clone();
    let usized_how_many_digits = string_how_many_digits.trim().parse().unwrap();

    // buffer 비워주기
    buf.clear();
    io::stdin().read_line(&mut buf).unwrap();
    
    //println!("{}", usized_how_many_digits);

    let trimmed_input_string = buf.trim();
    let converted_string_to_char = trimmed_input_string.chars();
    
    let mut sum = 0;
    
    for chars in converted_string_to_char.take(usized_how_many_digits) {
        sum += chars.to_digit(10).unwrap();
    }
    
    println!("{}", sum);
}