responses={
    "hello":"Hi!there!How can i assist you today?",
    "products":"We have wide range of products available.?",
    "shipping":"hagsdvjasdasdadgadhj",
    "help":"jfgjhalka'lafvbvnhkjd",
    "bye":"htdfvbb ytad",
    "default":"i anno getuin",
}

def chatbot_response(user_input):
    user_input=user_input.lower();
    if "hello" in user_input:
        return responses["hello"]
    elif "products" in user_input:
        return responses["products"]
    elif "shipping" in user_input:
        return responses["shipping"]
    elif "bye" in user_input:
        return responses["bye"]
    else:
        return responses["default"]

print("chatbot:Hi welcome")
while True:
    user_input=input("User:")
    response=chatbot_response(user_input)
    print("chatbot:"+response)
    if "bye" in user_input.lower():
        break