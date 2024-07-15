#include "error_handler.hpp"

ErrorHandler::ErrorHandler(std::string _message, std::string _detail) : invalid_argument(_message), detail(_detail) {}
void ErrorHandler::show_error() { std::cout << what() << std::endl; /*show_detail();*/ }   //this is for debugging
std::string ErrorHandler::get_detail() { return detail; }

std::string ErrorHandler::get_page() {
    std::string body;
    body += "<!DOCTYPE html><html><head><link rel='stylesheet' href='home.css'><meta charset='UTF-8'><style>a:link";
    body += "{color: rgb(0, 0, 0);background-color: transparent;text-decoration: none;width:100%; font-size: xx-large;display:block;text-align: center;text-align: center;";
    body += "a:visited {color: rgb(65, 15, 212);background-color: transparent;text-decoration: none;width:100%; font-size: xx-large; display:block;text-align: center;}";
    body +="a:hover {color: rgb(23, 71, 194);background-color: transparent;text-decoration: underline;width:100%; font-size: xx-large;display:block;text-align: center;}";
    body += "a:active {color: yellow;background-color: transparent;text-decoration: underline;width:100%; font-size: xx-large;display:block; text-align: center;}";
    body += "</style></head><body class='body'><div><br/><br/><br/><br/><p style='text-align: center;'>";
    body += what();
    body += "! ";
    body += get_detail();
    body += "</p><a href='/'>home</a><br></div></body></html>";
    return body;
}